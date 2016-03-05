/*
题目大意：
实现一个LRU的cache。

解题思路：
对于LRUcache的两种操作，最好都实现复杂度为常数。
所以采用hash+list的方式。
双向链表来实现增删改查的常数

遇到的问题：
第一次自己手动实现双向链表。感觉好多情况都没有考虑好。这个程序也是调试了很久了。
这种程序以后一定要多多练习，多多注意。

再次阅读：
这个代码之前已经看过一次了，虽然实现的有些麻烦，不过还是实现了基本的功能。
然后可以参考一下直接使用STL中的hash和list两种容器实现的LRU：
class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }

    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
            if (cache.size() == _capacity) {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }

private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;

    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }

    HIPII cache;
    LI used;
    int _capacity;
};
*/
class LRUCache{
private:
    struct List{
        int key;
        int val;
        List *next;
        List *before;
        List(int k, int v):key(k),val(v),next(NULL),before(NULL){}
    };
    int cap;
    map<int, List *> cache;
    List *head;
    List *last;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        head = NULL;
        last = NULL;
    }
    
    int get(int key) {
        if(cache.count(key) != 0){
            mov(cache[key]);
            return head->val;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(cache.count(key) != 0){
            cache[key]->val = value;
            mov(cache[key]);
            return;
        }
        if(cache.size() == cap){
            pop();
        }
        insert(new List(key, value));
    }
    
    void mov(List *node){
        if(node == head)return;
        node->before->next = node->next;
        if(node != last){
            node->next->before = node->before;
        }else{
            last = node->before;
        }
        cache.erase(node->key);
        node->before = NULL;
        node->next = NULL;
        insert(node);
    }
    
    void pop(){
        if(head == last){
            cache.erase(head->key);
            delete head;
            head = NULL;
            last = NULL;
            return;
        }
        List *tmp = last;
        last = last->before;
        cache.erase(tmp->key);
        delete tmp;
        last->next = NULL;
    }
    
    void insert(List *node){
        if(head == NULL){
            head = node;
            last = node;
            cache[node->key] = node;
            return;
        }
        node->next = head;
        head->before = node;
        head = node;
        cache[node->key] = node;
    }
};
/*
第二次做：
估计这道题是最考验链表操作能力的了。
*/
class LRUCache{
private:
    struct ListNode {
        int key, val;
        ListNode *next, *pre;
        ListNode(int k, int v): key(k), val(v), next(NULL), pre(NULL) {}
    };
    
    typedef unordered_map<int, ListNode *> hash;
    
    int _cap, total;
    hash cache;
    ListNode *head, *tail;
    
    void insert(int k, int v) {
        auto next = head->next;
        head->next = new ListNode(k, v);
        head->next->pre = head;
        head->next->next = next;
        next->pre = head->next;
    }
    
    void erase(ListNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        delete node;
    }
    
    void pop() {
        auto remove = tail->pre;
        tail->pre = remove->pre;
        remove->pre->next = tail;
        delete remove;
    }
    
public:
    LRUCache(int capacity) {
        _cap = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->pre = head;
        total = 0;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } else {
            insert(key, cache[key]->val);
            erase(cache[key]);
            cache[key] = head->next;
            return cache[key]->val;
        }
    }
    
    void set(int key, int value) {
        if (cache.find(key) == cache.end()) {
            insert(key, value);
            cache[key] = head->next;
            total++;
            if (total > _cap) {
                cache.erase(tail->pre->key);
                pop();
                total--;
            }
        } else {
            insert(key, value);
            erase(cache[key]);
            cache[key] = head->next;
        }
    }
};