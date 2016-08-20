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
    // cyclic shift by n-1 times.
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
class Stack {
private:
    queue<int> *in, *out;
    queue<int> q1, q2;
public:
    Stack() {
        in = &q1;
        out = &q2;
    }
    // Push element x onto stack.
    void push(int x) {
        in->push(x);
        while (!out->empty()) {
            in->push(out->front());
            out->pop();
        }

        swap(in, out);
    }

    // Removes the element on top of the stack.
    void pop() {
        out->pop();
    }

    // Get the top element.
    int top() {
        return out->front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return out->empty();
    }
};
