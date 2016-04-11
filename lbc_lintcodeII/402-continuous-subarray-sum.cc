/*
题目大意；
给定一个数组，找到一个连续子数组，其和最大。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        vector<int> ans(2, -1);
        if (A.size() == 0) return ans;
        
        ans[0] = ans[1] = 0;
        int mx = A[0], cur = mx, last = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (cur < 0) {
                cur = A[i];
                last = i;
            } else {
                cur += A[i];
            }
            
            if (cur > mx) {
                ans[0] = last;
                ans[1] = i;
                mx = cur;
            }
        }
        
        return ans;
    }
};