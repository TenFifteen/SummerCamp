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
/*
第二次做：
这次想的不好，一开始就想着用一个栈来着，结果自己就想到了中间结果有可能为负这种情况，而且，
老是字符串和数字来回转效率也不是很好。
*/
class Solution {
private:
    string deleteBlanks(const string s) {
        string ans;
        for (auto ch : s) {
            if (ch != ' ') {
                ans.push_back(ch);
            }
        }
        return ans;
    }

    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

public:
    int calculate(string s) {
        string exp = deleteBlanks(s);

        stack<char> ops;
        stack<int> nums;
        int index = 0;
        while (index < exp.size()) {
            if (exp[index] == '+' || exp[index] == '-' || exp[index] == '(') {
                ops.push(exp[index]);
                index++;
            } else if (exp[index] == ')') {
                ops.pop();
                if (ops.size() > 0 && ops.top() != '(') {
                    int num2 = nums.top(); nums.pop();
                    int num1 = nums.top(); nums.pop();
                    if (ops.top() == '+') {
                        nums.push(num1 + num2);
                    } else {
                        nums.push(num1 - num2);
                    }
                    ops.pop();
                }
                index++;
            } else {
                int end = index+1;
                while (end < exp.size() && isDigit(exp[end])) end++;
                int num2 = stoi(exp.substr(index, end-index));
                if (ops.size() > 0 && ops.top() != '(') {
                    int num1 = nums.top(); nums.pop();
                    if (ops.top() == '+') {
                        nums.push(num1 + num2);
                    } else {
                        nums.push(num1 - num2);
                    }
                    ops.pop();
                } else {
                    nums.push(num2);
                }
                index = end;
            }
        }

        return nums.top();
    }
};
/*
 * good question, and very tedious
 */
class Solution {
private:
    string removeSpaces(const string s) {
        string ans(s);
        int len = 0;
        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i] != ' ') ans[len++] = ans[i];
        }
        return ans.substr(0, len);
    }

public:
    int calculate(string s) {
        s = removeSpaces(s);

        stack<char> ops;
        stack<int> nums;
        int index = 0;
        while (index < s.size()) {
            if (s[index] == '(') {
                ops.push(s[index]);
            } else if (s[index] == '+' || s[index] == '-') {
                ops.push(s[index]);
            } else if (s[index] == ')') {
                if (ops.top() == '(') ops.pop();
                else {
                    int now = 0;
                    while (ops.top() != '(') {
                        if (ops.top() == '-') {
                            now -= nums.top();
                        } else {
                            now += nums.top();
                        }
                        nums.pop();
                        ops.pop();
                    }
                    ops.pop();
                    now += nums.top(); nums.pop();
                    nums.push(now);
                }
            } else {
                int next = index+1;
                while (next < s.size() && s[next] >= '0' && s[next] <= '9') {
                    next++;
                }
                int num = stoi(s.substr(index, next-index));
                nums.push(num);
                index = next-1;
            }
            index++;
        }

        int ans = 0;
        while (ops.size() > 0) {
            if (ops.top() == '-') {
                ans -= nums.top();
            } else {
                ans += nums.top();
            }
            ops.pop();
            nums.pop();
        }
        ans += nums.top();
        return ans;
    }
};
