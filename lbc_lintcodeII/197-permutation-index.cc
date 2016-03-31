/*
题目大意：
给定一个无重复的数组，问如果算排列，这是第多少个？

解题思路:
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        if (A.size() < 2) return A.size();
        
        int n = A.size();
        long long ans = 1, mul = 1;
        for (int i = n-2; i >= 0; --i) {
            int cnt = 0;
            for (int j = i+1; j < n; ++j) { // can be optimize by segmenttree
                if (A[j] < A[i]) cnt++;
            }
            ans += cnt*mul;
            mul *= n-i;
        }
        
        return ans;
    }
};