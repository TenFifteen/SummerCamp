/*
题目：22 % 排列序号II 中等

题目大意：
给定一个数组，其中元素有重复。问该排列在所有排列中是第几个？

解题思路：
直接求。见代码

遇到的问题：
一开始忘记了算上A[i]了。
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        if (A.size() == 0) return 0;
        long long ret = 0;
        for (int i = 0; i < A.size()-1; ++i) {
            int cnt = 0;
            unordered_map<int, int> um;
            um[A[i]]++;
            for (int j = i+1; j < A.size(); ++j) {
                um[A[j]]++;
                if (A[j] < A[i]) {
                    cnt++;
                }
            }
            if (cnt != 0) {
                ret += cnt * perm(A.size()-i-1) / sub(um);
            }
        }
        return ret+1;
    }
    
private:
    long long perm(int n) {
        long long ret = 1;
        for (int i = 2; i <= n; ++i) {
            ret *= i;
        }
        return ret;
    }
    
    long long sub(unordered_map<int, int> &um) {
        long long ret = 1;
        for (auto u : um) {
            ret *= perm(u.second);
        }
        return ret;
    }
};
