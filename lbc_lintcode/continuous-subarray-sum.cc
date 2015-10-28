/*
题目：21 % 连续子数组求和 中等

题目大意：
给定一个数组，求其连续的最大字段和

解题思路：
见代码

遇到的问题：
没有问题。
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
        vector<int> ans(2);
        if (A.size() == 0) return ans;
        int max = INT_MIN;
        int sum = 0;
        int last = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            if (sum > max) {
                max = sum;
                ans[0] = last;
                ans[1] = i;
            }
            if (sum <= 0) {
                sum = 0;
                last = i+1;
            }
        }
        return ans;
    }
};
