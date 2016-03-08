/*
题目大意：
给定一个vector表示的数字，将该数字加1.

解题思路：
直接加

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        vector<int> ans(digits.size()+1, 0);
        int n = digits.size(), carry = 1;
        
        for (int i = n-1; i >= 0; --i) {
            carry += digits[i];
            ans[i+1] = carry%10;
            carry /= 10;
        }
        
        if (carry) {
            ans[0] = carry;
            return ans;
        } else return vector<int>(ans.begin()+1, ans.end());
    }
};