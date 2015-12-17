/*
题目大意：
给定一个数字n，将其表示成平方和的形式，问最少用多少个平方和

解题思路：
动态规划

遇到的问题：
没有问题。
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i*i <= n; i++) {
            squares.push_back(i*i);
        }
        
        int k = squares.size();
        if (squares[k-1] == n) return 1;
        
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = i+1;
        }
        for (int i = 1; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                if (squares[i] < j+1) {
                    dp[j] = min(dp[j], dp[j-squares[i]] + 1);
                } else if (squares[i] == j+1) {
                    dp[j] = 1;
                }
            }
        }
        
        return dp[n-1];
    }
};