/*
题目：18 % LRU缓存策略 困难

题目大意：
实现一个LRU的容器。

解题思路：
用map和双向链表实现的。

遇到的问题：
一个是将remove写成了delete，调了好久。
一个是忘记了cap==1的时候的特殊场景。

感觉这个题目上次在leetcode上做的就不好，调了好久。这次又是这样，
而且，这次还没有想到思路，还是回去看的原来的思路
感觉代码写的非常的难看，所以这道题目一定要看看别人怎么写的。
*/
class LRUCache{
private:
    struct Node {
        int key;
        int val;
        Node *next, *pre;
        Node(int key, int val) {
            next = pre = NULL;
            this->key = key;
            this->val = val;
        }
    };
    
    Node * remove(Node *node) {
        auto ret = node;
        node->pre->next = node->next;
        if (node->next != NULL) {
            node->next->pre = node->pre;
        } else {
            tail = node->pre;
        }
        return ret;
    }
    
    void add(Node *node) {
        if (head == NULL) {
            head = node;
            node->pre = node->next = NULL;
            tail = head;
        } else {
            node->next = head;
            head->pre = node;
            node->pre = NULL;
            head = node;
        }
    }
    
    Node *head = NULL;
    Node *tail = NULL;
    int cap = 0;
    unordered_map<int, Node*> buf;
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        // write your code here
        cap = capacity;
    }
    
    // @return an integer
    int get(int key) {
        // write your code here
        if (buf.find(key) != buf.end()) {
            if (head != buf[key]) {
                remove(buf[key]);
                add(buf[key]);
            }
            return head->val;
        }
        return -1;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        if (buf.find(key) != buf.end()) {
            if (buf[key] != head) {
                remove(buf[key]);
                add(buf[key]);
            }
            head->val = value;
        } else {
            if (buf.size() == cap) {
                if (cap == 1) {
                    buf.erase(head->key);
                    head->key = key;
                    head->val = value;
                    buf[head->key] = head;
                    return;
                }
                buf.erase(tail->key);
                auto ret = remove(tail);
                ret->key = key;
                ret->val = value;
                add(ret);
                buf[key] = head;
            } else {
                auto now = new Node(key, value);
                add(now);
                buf[key] = head;
            }
        }
    }
};
