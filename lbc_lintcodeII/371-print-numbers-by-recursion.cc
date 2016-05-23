/*
题目大意：
递归打印出所有长度小于等于n的数字。

解题思路：
见代码。

遇到的问题：
没有太大问题。
只是一开始没有注意到需要按照顺序。
*/
class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        if (n < 1) return vector<int>();
        
        if (n == 1) {
            vector<int> ans(9);
            for (int i = 1; i < 10; ++i) {
                ans[i-1] = i;
            }
            return ans;
        }
        
        vector<int> ans = numbersByRecursion(n-1);
        int index = 0, last = ans.size();
        while (to_string(ans[index]).size() < n-1) index++;
        
        while (index < last) {
            for (int i = 0; i < 10; ++i) {
                ans.push_back(ans[index] * 10 + i);
            }
            index++;
        }
        
        return ans;
    }
};
