/*
题目：29 % 加一 容易

题目大意：
给定一个vector表示的数，然后将其加1

解题思路：
见代码

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        int c = 1;
        for (int i = digits.size()-1; i >= 0; --i) {
            c += digits[i];
            digits[i] = c % 10;
            c /= 10;
        }
        if (c) {
            vector<int> ans(digits.size()+1);
            ans[0] = 1;
            for (int i = 1; i < ans.size(); ++i) {
                ans[i] = digits[i-1];
            }
            return ans;
        } else {
            return digits;
        }
    }
};
