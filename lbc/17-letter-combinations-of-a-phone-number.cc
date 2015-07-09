/*
题目大意：
给一个数字组成的字符串，然后给出根据9宫格键盘布局，所有可能对应的字符串。

解题思路：
明显就是一个回溯。把当前的最前边的字符对应的几种情况分别尝试，然后再回溯。

遇到的问题：
并没有太大问题。不过sub函数可以再简练一点，多种情况只是判断左右边界，然后后边统一
进行递归函数的调用。
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)return ans;
        sub(ans,"",digits);
        return ans;
    }
    
    void sub(vector<string> &ans, string cur, string digits){
        if(digits == ""){
            ans.push_back(cur);
            return;
        }
        if(digits[0] < '7'){
            for(char ch = (digits[0]-'2')*3+'a'; ch != (digits[0]-'2')*3+'d'; ++ch){
                cur.push_back(ch);
                sub(ans,cur,digits.substr(1,digits.size()-1));
                cur.pop_back();
            }
        }else if(digits[0] == '7'){
            for(char ch = 'p'; ch != 't'; ++ch){
                cur.push_back(ch);
                sub(ans,cur,digits.substr(1,digits.size()-1));
                cur.pop_back();
            }
        }else if(digits[0] == '8'){
            for(char ch = 't'; ch != 'w'; ++ch){
                cur.push_back(ch);
                sub(ans,cur,digits.substr(1,digits.size()-1));
                cur.pop_back();
            }
        }else{
            for(char ch = 'w'; ch != 'w'+4; ++ch){
                cur.push_back(ch);
                sub(ans,cur,digits.substr(1,digits.size()-1));
                cur.pop_back();
            }
        }
    }
};