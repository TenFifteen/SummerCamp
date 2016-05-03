/**
 * Problem: As the title described, you should only use two stacks to implement a queue's actions.
 *          The queue should support push(element), pop() and top() where pop is pop the first(a.k.a front) element in the queue.
 *          Both pop and top methods should return the value of first element.
 * Solve: two stack: one to push, and one to pop. When move data, we should keep stack2 is empty.
 * Tips: pop() also return value
 */
class Queue {
    public:
        stack<int> stack1;
        stack<int> stack2;

        Queue() {
            // do intialization if necessary
        }

        void push(int element) {
            stack1.push(element);
        }

        int pop() {
            if (stack2.empty()) {
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            int top = stack2.top();
            stack2.pop();

            return top;
        }

        int top() {
            if (stack2.empty()) {
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            return stack2.top();
        }
};

