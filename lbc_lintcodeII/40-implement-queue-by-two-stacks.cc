/*
题目大意：
用两个栈来实现一个队列

解题思路：
见代码

遇到的问题：
没有。
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
        if (stack2.size() == 0) {
            while (stack1.size() > 0) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

    int top() {
        // write your code here
        if (stack2.size() == 0) {
            while (stack1.size() > 0) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        return stack2.top();
    }
};
