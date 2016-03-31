/*
题目大意：
最长连续上升子序列

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        if (A.size() < 2) return A.size();
        
        int len = 1;
        int last = 0, index = 1;
        while (index < A.size()) {
            if (A[index] > A[index-1]) {
                index++;
                len = max(index-last, len);
            } else {
                last = index++;
            }
        }
        
        last = A.size()-1, index = last-1;
        while (index >= 0) {
            if (A[index] > A[index+1]) {
                index--;
                len = max(last-index, len);
            } else {
                last = index--;
            }
        }
        
        return len;
    }
};