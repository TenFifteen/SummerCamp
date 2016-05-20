/*
题目大意：
给定一个排列。问该排列在所有的排列中是第多少个？

集体思路：
见代码。

遇到的问题：
这次竟然不太会做了。
参考了一下之前的代码，发现其实原来有些东西是没有想清楚的。但是的确是work的。
这次又仔细想了一下，的确是可以work的。只不过这次知道了为什么work了。
*/
class Solution {
    long long perm(int c) {
        long long ret = 1;
        for (int i = 2; i <= c; ++i) {
            ret *= i;
        }
        return ret;
    }
    
    long long sub(unordered_map<int, int> &um) {
        long long ret = 1;
        for (auto p : um) {
            ret *= perm(p.second);
        }
        return ret;
    }
    
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        if (A.size() == 0) return 0;
        
        long long ret = 1;
        for (int i = 0; i < A.size(); ++i) {
            int cnt = 0;
            unordered_map<int, int> um;
            um[A[i]]++;
            
            for (int j = i+1; j < A.size(); ++j) {
                um[A[j]]++;
                if (A[j] < A[i]) {
                    cnt++;
                }
            }
            
            ret += cnt * perm(A.size()-i-1) / sub(um);
        }
        
        return ret;
    }
};
