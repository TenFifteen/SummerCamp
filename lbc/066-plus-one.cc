/*
题目大意：
给两个数组表示的非负整数，加起来。

解题思路：
大整数。

遇到的问题：
一次通过。
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int yu = 1;
        int index = digits.size()-1;
        while(index >= 0 || yu){
            yu += digits[index--];
            ans.push_back(yu%10);
            yu /= 10;
        }
        for(int i = 0; i < ans.size()/2; ++i){
            swap(ans[i], ans[ans.size()-1-i]);
        }
        return ans;
    }
};