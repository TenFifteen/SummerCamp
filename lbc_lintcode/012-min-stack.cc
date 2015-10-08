/*
题目：带最小值操作的栈 中等

题目大意：
实现一个带有求最小值的栈

解题思路：
另外存储一个栈，其中存放最小值

遇到的问题：
对于标准库中的方法，使用的时候要注意命名冲突。
*/
class MinStack {
private:
    stack<int> sta;
    stack<int> min_sta;
    
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        if (min_sta.empty()) {
            min_sta.push(number);
        } else {
            min_sta.push(std::min(number, min_sta.top()));
        }
        sta.push(number);
    }

    int pop() {
        // write your code here
        int ret = sta.top();
        sta.pop();
        min_sta.pop();
        return ret;
    }

    int min() {
        // write your code here
        return min_sta.top();
    }
};

