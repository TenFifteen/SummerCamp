/*
题目大意：
给一个数字，输出所有可能的括号的组合。

解题思路：
就是一个回溯问题。如果当前还剩下的右括号为0，则可以输出；如果左右括号数一样，
那么只能输出左括号；另外就是左右都可以输出的。

遇到的问题：
不要忘记输出之后要返回。
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        sub(n, n, ans, cur);
        return ans;
    }
    
    void sub(int left, int right, vector<string> &ans, string &cur){
        if(right == 0){
            ans.push_back(cur);
            return;
        }
        if(left == right){
            cur.push_back('(');
            sub(left-1, right, ans, cur);
            cur.pop_back();
        }else{
            if(left > 0){
                cur.push_back('(');
                sub(left-1, right, ans, cur);
                cur.pop_back();
            }
            cur.push_back(')');
            sub(left, right-1, ans, cur);
            cur.pop_back();
        }
    }
};