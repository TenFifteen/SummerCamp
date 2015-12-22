/*
题目大意：
给一堆字符串，然后找出找些字符串的最长公共前缀。

解题思路：
直接对这些字符串遍历就行了。当然了，需要注意各种边界条件。

遇到的问题：
这个题一次通过，还可以。

再次阅读：
我以为这样笨笨的算法会有更好的改进的呢，竟然DISCUSS中大家认为最好的解法
也是这样子做。
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.size() == 0)return ans;
        int index = 0;
        while(true){
            bool done = false;
            if(index >= strs[0].size())break;
            for(int i = 1; i < strs.size(); ++i){
                if(index >= strs[i].size() || strs[i][index] != strs[0][index]){
                    done = true;
                    break;
                }
            }
            if(done){
                break;
            }
            index++;
        }
        return strs[0].substr(0,index);
    }
};