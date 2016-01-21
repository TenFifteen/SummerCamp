/*
题目大意：
求波兰表达式的结果

解题思路：
用栈来模拟

遇到的问题：
一次通过。
代码还可以再精简一下。

再次阅读：
这道题比较简单，直接用一个stack就可以解决了。
看了一下DISCUSS，其实也是这种方法。还有的人用的是递归的方法。

*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;
        for(int i = 0; i < tokens.size(); ++i){
            if(tokens[i] == "+"){
                int right = ans.top();
                ans.pop();
                int left = ans.top();
                ans.pop();
                ans.push(left+right);
            }else if(tokens[i] == "-"){
                int right = ans.top();
                ans.pop();
                int left = ans.top();
                ans.pop();
                ans.push(left-right);
            }else if(tokens[i] == "*"){
                int right = ans.top();
                ans.pop();
                int left = ans.top();
                ans.pop();
                ans.push(left*right);
            }else if(tokens[i] == "/"){
                int right = ans.top();
                ans.pop();
                int left = ans.top();
                ans.pop();
                ans.push(left/right);
            }else{
                ans.push(stoi(tokens[i]));
            }
        }
        return ans.top();
    }
};