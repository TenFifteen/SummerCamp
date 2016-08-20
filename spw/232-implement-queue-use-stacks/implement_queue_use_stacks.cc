/**
 * Problem: Implement the following operations of a queue using stacks.
 * Solve: use two stacks to simulate a queue. Just append element to
 *        stack1 every time, when pop or top, if stack2 is not empty,
 *        then give result directly. Pop all the elements of stack1 into stack2
 *        otherwise.
 * Tips: no
 */
class Queue {
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        // Push element x to the back of queue.
        void push(int x) {
            s1.push(x);
        }

        // Removes the element from in front of queue.
        void pop(void) {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            if (s2.empty()) return;
            s2.pop();
        }

        // Get the front element.
        int peek(void) {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            if (s2.empty()) return 0;
            return s2.top();
        }

        // Return whether the queue is empty.
        bool empty(void) {
            return s1.empty() && s2.empty();
        }
};


class Queue {
    private:
        stack<int> in, out;
    public:
        // Push element x to the back of queue.
        void push(int x) {
            in.push(x);
        }

        // Removes the element from in front of queue.
        void pop(void) {
            if (out.empty()) {
                while (!in.empty()) {
                    out.push(in.top());
                    in.pop();
                }
            }
            out.pop();
        }

        // Get the front element.
        int peek(void) {
            if (out.empty()) {
                while (!in.empty()) {
                    out.push(in.top());
                    in.pop();
                }
            }
            return out.top();
        }

        // Return whether the queue is empty.
        bool empty(void) {
            return in.empty() && out.empty();
        }
};
