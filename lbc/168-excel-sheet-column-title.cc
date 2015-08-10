/*
题目大意：
给定一个正整数，求其对应的excel表的字母表示

解题思路：
相当于是转化为26进制的数。

遇到的问题：
一次通过。
*/
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n){
            if(n % 26){
                ans.push_back('A' + n%26-1);
                n /= 26;
            }else{
                ans.push_back('Z');
                n = (n-1)/26;
            }
        }
        for(int i = 0; i < ans.size()/2; ++i){
            swap(ans[i], ans[ans.size()-1-i]);
        }
        return ans;
    }
};