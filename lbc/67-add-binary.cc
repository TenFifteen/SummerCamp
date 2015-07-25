/*
题目大意：
给两个01的字符串。将其相加。

解题思路：
直接做就是了，类似于大整数。

遇到的问题：
一次通过。
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int index_a = a.size()-1;
        int index_b = b.size()-1;
        int yu = 0;
        while(index_a >= 0 || index_b >= 0 || yu){
            if(index_a >= 0){
                yu += a[index_a--]-'0';
            }
            if(index_b >= 0){
                yu += b[index_b--]-'0';
            }
            ans.push_back('0'+yu%2);
            yu /= 2;
        }
        for(int i = 0; i < ans.size()/2; ++i){
            swap(ans[i], ans[ans.size()-1-i]);
        }
        return ans;
    }
};