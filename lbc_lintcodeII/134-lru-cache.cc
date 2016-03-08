/*
题目大意：
设计一个LRU缓存器。

解题思路：
用双向链表和hash一起实现。

遇到的问题：
实现问题不是很大，不过就是初始化的时候除了一点小问题。
*/
class LRUCache{
    class ListNode {
    public:
        ListNode *pre, *next;
        int val, key;
        ListNode(): pre(NULL), next(NULL) {}
    };
    
    int _cap, _size;
    unordered_map<int, ListNode *> hash;
    ListNode *head, *tail;
    
    void push(int key, int val) {
        ListNode *tmp = new ListNode();
        tmp->key = key;
        tmp->val = val;
        
        tmp->next = head->next;
        head->next->pre = tmp;
        head->next = tmp;
        tmp->pre = head;
    }
    
    void erase(ListNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        delete node;
    }
    
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        // write your code here
        _cap = capacity;
        _size = 0;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->pre = head;
    }
    
    // @return an integer
    int get(int key) {
        // write your code here
        if (hash.find(key) == hash.end()) return -1;
        else {
            push(key, hash[key]->val);
            erase(hash[key]);
            hash[key] = head->next;
            
            return hash[key]->val;
        }
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        push(key, value);
        if (hash.find(key) == hash.end()) {
            _size++;
        } else {
            erase(hash[key]);
        }
        
        hash[key] = head->next;
        
        if (_size > _cap) {
            _size--;
            hash.erase(tail->pre->key);
            erase(tail->pre);
        }
    }
};