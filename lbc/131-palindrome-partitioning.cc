/*
题目大意：
给定一个字符串，问将s划分成都是回文子串的方法有哪些？

解题思路：
递归。
判定s的一个从后往前的所有字串是否是回文，如果是就递归找前面的字串的。

遇到的问题：
没有问题。
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.size() == 0)return ans;
        if(s.size() == 1){
            vector<string> tmp;
            tmp.push_back(s);
            ans.push_back(tmp);
            return ans;
        }
        
        for(int i = s.size()-1; i >= 0; --i){
            bool isPa = true;
            for(int j = s.size()-1; j > s.size()-1-(s.size()-i)/2; --j){
                if(s[j] != s[s.size()+i-j-1]){
                    isPa = false;
                    break;
                }
            }
            if(isPa == true){
                if(i == 0){
                    vector<string> tmp;
                    tmp.push_back(s);
                    ans.push_back(tmp);
                    break;
                }
                auto ret = partition(s.substr(0, i));
                for(auto r:ret){
                    r.push_back(s.substr(i, s.size()-i));
                    ans.push_back(r);
                }
            }
        }
        return ans;
    }
};