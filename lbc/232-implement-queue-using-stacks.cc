/*
题目大意：
用栈来实现队列。

解题思路：
用两个栈。a栈管push。b栈管top和pop，当b为空的时候，将a全部放入b中。

遇到的问题：
peek竟然忘了写return。。。
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