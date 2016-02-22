/*
题目大意：
给定一个表达式，有括号，加减号，以及空格。求值。

解题思路：
用栈来存放当前待处理的数据和操作符。

遇到的问题：
一开始忘记了在匹配到括号后，还要将缓存的可以计算的符号都计算了。

再次阅读：
虽然感觉思路没啥问题，但是总感觉代码有些乱。
下面这套代码就很简洁：仔细看一下，感觉简洁的有些过分啊。
class Solution {
public:
    int calculate(string s) {
        stack <int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};
*/
class Solution {
public:
    int calculate(string s) {
        string tmp;
        for(auto ch : s){
            if(ch == ' ')continue;
            tmp.push_back(ch);
        }
        s = tmp;
        int index = 0;
        stack<char> ops;
        stack<int> nums;
        while(index < s.size()){
            if(s[index] == '+' || s[index] == '-' || s[index] == '('){
                ops.push(s[index]);
                index++;
            }else if(s[index] == ')'){
                ops.pop();
                index++;
                
                while(!ops.empty() && ops.top() != '('){
                    int right = nums.top();
                    nums.pop();
                    int left = nums.top();
                    nums.pop();
                    if(ops.top() == '-'){
                        nums.push(left-right);
                    }else{
                        nums.push(left+right);
                    }
                    ops.pop();
                }
            }else{
                int end = index+1;
                while(end < s.size() && isDigit(s[end]))++end;
                int right = stoi(s.substr(index, end-index));
                if(ops.empty()){
                    nums.push(right);
                }
                else if(ops.top() == '+'){
                    int left = nums.top();
                    nums.pop();
                    ops.pop();
                    nums.push(left + right);
                }else if(ops.top() == '-'){
                    int left = nums.top();
                    nums.pop();
                    ops.pop();
                    nums.push(left - right);
                }else{
                    nums.push(right);
                }
                index = end;
            }
        }
        return nums.top();
    }
    
    bool isDigit(char ch){
        return ch >= '0' && ch <= '9';
    }
};