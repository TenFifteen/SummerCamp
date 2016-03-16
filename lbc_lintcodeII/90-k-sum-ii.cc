/*
题目大意：
给定一个数组，数字都是unique的，找到所有k歌数的和为target的组合。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
    void dfs(vector<vector<int>> &ans, vector<int> &now, 
             vector<int> &A, int k, int target, int sum, int index) {
        if (k == 0) {
            if (sum == target) {
                ans.push_back(now);
            }
            return;
        }
        
        if (A.size()-index < k) return;
        
        for (int i = index; i < A.size(); ++i) {
            now.push_back(A[i]);
            dfs(ans, now, A, k-1, target, sum+A[i], i+1);
            now.pop_back();
        }
    }
    
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int>> ans;
        vector<int> now;
        dfs(ans, now, A, k, target, 0, 0);
        return ans;
    }
};
