/*
题目大意：
实现一个具有求最小值的栈。

解题思路：
用两个栈，一个用来存放原来的数，一个用来存放最小值。

遇到的问题：
一次通过。
*/
class MinStack {
private:
    stack<int> a,b;
public:
    void push(int x) {
        a.push(x);
        if(b.empty()){
            b.push(x);
        }else{
            b.push(min(x, b.top()));
        }
    }

    void pop() {
        a.pop();
        b.pop();
    }

    int top() {
        return a.top();
    }

    int getMin() {
        return b.top();
    }
};