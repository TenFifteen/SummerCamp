/*
题目：26 % 排列序号 容易

题目大意：
给定一个没有重复的数组，问当前的数组在整个的排列中的排名是多少

解题思路：
直接求，见代码

遇到的问题：
这么高的复杂度竟然过了。
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        long long ret = 0;
        for (int i = 0; i < A.size(); ++i) {
            int cnt = 0;
            for (int j = i+1; j < A.size(); ++j) {
                if (A[j] < A[i]) {
                    cnt ++;
                }
            }
            if (cnt > 0) {
                ret += cnt * sub(A.size()-i-1);
            }
        }
        return ret+1;
    }
    
    long long sub(int n) {
        long long ret = 1;
        for (int i = 1; i <= n; ++i) {
            ret *= i;
        }
        return ret;
    }
};
