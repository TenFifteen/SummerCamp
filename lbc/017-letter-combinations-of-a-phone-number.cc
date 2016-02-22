/*
题目大意：
给一个数字组成的字符串，然后给出根据9宫格键盘布局，所有可能对应的字符串。

解题思路：
明显就是一个回溯。把当前的最前边的字符对应的几种情况分别尝试，然后再回溯。

遇到的问题：
并没有太大问题。不过sub函数可以再简练一点，多种情况只是判断左右边界，然后后边统一
进行递归函数的调用。

再次阅读：
虽然之前做的没有太大问题。但是这个题可以写的更简洁一些，把每个数字对应的字母字符串
先缓存下来，然后直接遍历就行了。另外就是注意0和1的处理。虽然这道题里没有考察这部分，
但是还是应该注意一下的。
下面是比较简洁的DISCUSS中的代码：
vector<string> letterCombinations(string digits) {
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;
    }
    return res;
}
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
/*
第二次做：
这次果断选择了之前DISCUSS中的方法做了。
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0) return ans;
        ans.push_back("");
        
        unordered_map<char, string> mapping;
        mapping['1'] = "";
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
        mapping['*'] = "*";
        mapping['0'] = " ";
        mapping['#'] = "#";
        
        for (auto ch : digits) {
            vector<string> next;
            for (auto s : ans) {
                if (mapping[ch].size()) {
                    for (auto m : mapping[ch]) {
                        next.push_back(s + m);
                    }
                } else {
                    next.push_back(s);
                }
            }
            ans = next;
        }
        
        return ans;
    }
};