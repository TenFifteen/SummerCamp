/**
 * Problem: Design and implement a data structure for Least Recently Used (LRU) cache.
 *          It should support the following operations: get and set.
 *          get(key) - Get the value (will always be positive) of the key if the key
 *          exists in the cache, otherwise return -1.
 *          set(key, value) - Set or insert the value if the key is not already present.
 *          When the cache reached its capacity, it should invalidate the least recently
 *          used item before inserting a new item.
 * Solve: just do it.
 * Tips: set
 */
class MyNode {
    public:
        MyNode *prev, *next;
        int key, val;

        MyNode(int k, int v) {
            this->key = k;
            this->val = v;
            this->prev = this->next = NULL;
        }
};

class LRUCache{
    public:
        // @param capacity, an integer
        LRUCache(int capacity) {
            this->head = new MyNode(0, 0);
            this->tail = new MyNode(0, 0);

            head->next = head->prev = tail;
            tail->next = tail->prev = head;

            cap = capacity;
            size = 0;
        }

        // @return an integer
        int get(int key) {
            if (mem.find(key) == mem.end()) return -1;

            attach(detach(mem[key]));
            return mem[key]->val;
        }

        // @param key, an integer
        // @param value, an integer
        // @return nothing
        void set(int key, int value) {
            MyNode *now = NULL;

            if (mem.find(key) == mem.end()) {
                if (size == cap) {
                    now = detach(tail->prev);
                    mem.erase(now->key);

                    now->key = key;
                    now->val = value;
                } else {
                    now = new MyNode(key, value);
                    ++size;
                }
            } else {
                now = detach(mem[key]);
                now->val = value;
            }

            attach(now);
            mem[key] = now;
        }

    private:
        unordered_map<int, MyNode *> mem;
        MyNode *head, *tail;

        int cap, size;

        MyNode *detach(MyNode *node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            return node;
        }

        MyNode *attach(MyNode *node) {
            node->next = head->next;
            node->prev = head;

            head->next = node;
            node->next->prev = node;

            return node;
        }
};
