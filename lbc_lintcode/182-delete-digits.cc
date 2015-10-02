/*
题目：16 % 删除数字 中等

题目大意：
给定一个数字的字符串表示，然后从中删掉k个数字。问最后剩下的数字组成的数的最小值是多少？

解题思路：
动归

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        vector<vector<string>> dp(A.size()+1, vector<string>(k+1));
        for (int i = 1; i <= A.size(); ++i) {
            dp[i][0] = A.substr(0, i);
        }
        for (int i = 1; i <= k; ++i) {
            for (int j = i+1; j <= A.size(); ++j) {
                dp[j][i] = myMin(dp[j-1][i-1], dp[j-1][i]+A[j-1]);
            }
        }
        return dp[A.size()][k];
    }
    
    string myMin(string s1, string s2) {
        int index1 = 0, index2 = 0;
        while (index1 < s1.size() && s1[index1] == '0') index1++;
        while (index2 < s2.size() && s2[index2] == '0') index2++;
        s1 = s1.substr(index1, s1.size());
        s2 = s2.substr(index2, s2.size());
        if (s1.size() > s2.size()) {
            return s2;
        } 
        if (s1.size() < s2.size()) {
            return s1;
        }
        if (s1 > s2) {
            return s2;
        }
        return s1;
    }
};

