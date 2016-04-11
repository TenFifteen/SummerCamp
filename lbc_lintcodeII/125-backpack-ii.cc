/*
题目大意：
一个简单的01背包。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        vector<int> dp(m+1, 0);
        
        for (int i = 0; i < A.size(); ++i) {
            for (int j = m; j > 0; --j) {
                if (j < A[i]) break;
                dp[j] = max(dp[j], dp[j-A[i]]+V[i]);
            }
        }
        
        return dp[m];
    }
};