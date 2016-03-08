/*
题目大意：
实现一个有min功能的栈。

解题思路：
用两个栈来实现，s1来存放正常的数据，s2用来存放最小值。

遇到的问题：
一开始没有注意pop还有返回值。
*/
class MinStack {
    stack<int> s1, s2;
    
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        s1.push(number);
        if (s2.size() == 0 || number <= s2.top()) {
            s2.push(number);
        }
    }

    int pop() {
        // write your code here
        int p = s1.top();
        s1.pop();
        if (p == s2.top()) s2.pop();
        
        return p;
    }

    int min() {
        // write your code here
        return s2.top();
    }
};
