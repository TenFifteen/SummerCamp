/*
题目：41 % 用栈实现队列 中等

题目大意：
用两个栈实现一个队列。

解题思路：
1进，2出。

遇到的问题：
没有问题。
*/
class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }

    int pop() {
        // write your code here
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        auto ret = stack2.top();
        stack2.pop();
        return ret;
    }

    int top() {
        // write your code here
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
};

