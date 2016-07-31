/*
题目大意：
用栈来实现队列。

解题思路：
用两个栈。a栈管push。b栈管top和pop，当b为空的时候，将a全部放入b中。

遇到的问题：
peek竟然忘了写return。。。

再次阅读：
感觉基本之前的这种思路已经是最好了。
*/
class Queue {
private:
    stack<int> a,b;
public:
    // Push element x to the back of queue.
    void push(int x) {
        a.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(b.size() == 0){
            while(a.size() > 0){
                b.push(a.top());
                a.pop();
            }
        }
        b.pop();
    }

    // Get the front element.
    int peek(void) {
        if(b.size() == 0){
            while(a.size() > 0){
                b.push(a.top());
                a.pop();
            }
        }
        return b.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return a.empty() && b.empty();
    }
};
/*
第二次做：
没有问题，比较经典。
*/
class Queue {
private:
    stack<int> s1, s2;

public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (s2.size() == 0) {
            while (s1.size() > 0) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if (s2.size() == 0) {
            while (s1.size() > 0) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.size() == 0 && s2.size() == 0;
    }
};
/*
 * good
 */
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
        if (out.size() == 0) {
            while (in.size() > 0) {
                out.push(in.top());
                in.pop();
            }
        }
        out.pop();
    }

    // Get the front element.
    int peek(void) {
        if (out.size() == 0) {
            while (in.size() > 0) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return in.size() == 0 && out.size() == 0;
    }
};
