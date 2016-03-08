/**
 * Problem: Implement the following operations of a stack using queues.
 * Solve: use one queue. Adjust when push.
 * Tips: in the top, please do not forget to return.
 */
class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        int n = q.size();
        while (--n) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};