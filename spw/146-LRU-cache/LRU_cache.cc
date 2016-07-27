#include <unordered_map>
#include <iostream>

using namespace std;

struct Node{
    // key used to delete item in the hash map.
    int key, val;
    Node *prev, *next;
    Node(int k, int v): key(k), val(v) {}

};

/**
 * Problem: Design and implement a data structure for Least Recently Used(LRU, that is to say,
 *          swap out the oldest item), get and set are all called 'used'.
 * Solve: Hash map + doubly linked list. Map used to access in O(1) time.
 * Tips: see comments below.
 */
class LRUCache{
    public:
        LRUCache(int capacity) {
            size = capacity;
            c = 0;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            head->prev = tail;
            tail->next = head;
            tail->prev = head;
        }

        ~LRUCache() {
            Node *iter = head->next;
            while(iter != tail) {
                Node *tmp = iter;
                iter = iter->next;
                delete tmp;

            }
            delete head;
            delete tail;
        }

        int get(int key) {
            if (mem.find(key) == mem.end()) return -1;

            Node *now = mem[key];
            attach_node(detach_node(now));
            return now->val;

        }

        void set(int key, int value) {
            if (mem.find(key) != mem.end()) {
                // remember to set the value.
                mem[key]->val = value;
                attach_node(detach_node(mem[key]));
            } else {
                if (size == 0) return;
                if (c == size && c > 0) {
                    mem.erase(tail->prev->key);
                    delete_node(tail->prev);
                    --c;
                }

                mem[key] = attach_node(new Node(key, value));
                ++c;

            }

        }
    private:
        int size;
        int c;
        Node *head;
        Node *tail;
        unordered_map<int, Node*> mem;

        // used to chain operation
        Node* detach_node(Node *now) {
            now->prev->next = now->next;
            now->next->prev = now->prev;
            return now;

        }

        void delete_node(Node *now) {
            delete detach_node(now);

        }

        Node* attach_node(Node *now) {
            now->next = head->next;
            now->prev = head;

            head->next = now;
            now->next->prev = now;

            return now;

        }

};

class LRUCache{
    private:
        class Node{
            public:
                Node *next, *prev;
                int key, val;
                Node(int k, int v): key(k), val(v) {}

        };

        Node *head, *tail;
        int size, total;
        unordered_map<int, Node*> mem;

        Node* detach(Node *node) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            return node;

        }

        Node *attach(Node *node) {
            node->next = head->next;
            node->prev = head;

            head->next = node;
            node->next->prev = node;

            return node;

        }
    public:
        LRUCache(int capacity) {
            size = 0, total = capacity;
            head = new Node(0, 0), tail = new Node(0, 0);
            head->next = head->prev = tail;
            tail->next = tail->prev = head;

        }

        int get(int key) {
            if (mem.find(key) == mem.end()) return -1;
            attach(detach(mem[key]));
            return mem[key]->val;
        }

        void set(int key, int value) {
            Node *now = NULL;
            if (mem.find(key) == mem.end()) {
                if (size < total) {
                    ++size;
                    now = new Node(key, value);
                } else {
                    now = detach(tail->prev);
                    // erase key first
                    mem.erase(now->key);
                    now->key = key;
                    now->val = value;
                }

            } else {
                now = detach(mem[key]);
                now->val = value;

            }

            attach(now);
            mem[key] = now;

        }

};
