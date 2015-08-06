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