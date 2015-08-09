/*
题目大意：
要求用队列实现栈。

解题思路：
假设当前的队列中的元素就是已经按照栈的要求排列了。
然后新来元素的时候，将其全部倒入另一个队列中，将该元素放进去，然后再将刚才的元素
倒回来。

遇到的问题：
一次通过。
不过不知道有没有复杂度第一点的实现方案？
*/
class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        if(q.empty()){
            q.push(x);
        }else{
            queue<int> tmp;
            while(!q.empty()){
                tmp.push(q.front());
                q.pop();
            }
            q.push(x);
            while(!tmp.empty()){
                q.push(tmp.front());
                tmp.pop();
            }
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