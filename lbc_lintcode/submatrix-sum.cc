/*
题目：19 % 和为零的子矩阵 中等

题目大意：
给定一个矩阵，找到一个子矩阵的和为0.要求复杂度n*n*n

解题思路：
之前做过一个一维的子数组和为0.当时就是将所有0-i的和都算出来放到一个
hash map中。然后如果后面有和等于前面的和，那么说明中间那段就是和为0.
现在就是将其扩展到二维。所有列的组合共有n*n种，每次找一次有n的复杂度。

遇到的问题：
一开始没有想到这个思路，还是看了别人的思路。
http://techinpad.blogspot.com/2015/06/lintcode-submatrix-sum.html
然后感觉自己写这种二维的东西的代码实在是难看的不忍卒读啊。
*/
class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        vector<vector<int>> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> sum(matrix);
        for (int i = 0;i < n; ++i) {
            int cur = 0;
            unordered_map<int, int> um;
            for (int j = 0; j < m; ++j) {
                cur += matrix[i][j];
                if (cur == 0) {
                    vector<int> tmp(2);
                    tmp[0] = i;
                    tmp[1] = 0;
                    ans.push_back(tmp);
                    tmp[1] = j;
                    ans.push_back(tmp);
                    return ans;
                }
                if (um.find(cur) != um.end()) {
                    vector<int> tmp(2);
                    tmp[0] = i;
                    tmp[1] = um[cur]+1;
                    ans.push_back(tmp);
                    tmp[1] = j;
                    ans.push_back(tmp);
                    return ans;
                }
                um[cur] = j;
            }
        }
        for (int len = 1; len < n; ++len) {
            for (int start = 0; start+len < n; ++start) {
                for (int i = 0; i < m; ++i) {
                    sum[start][i] += matrix[start+len][i];
                }
                int cur = 0;
                unordered_map<int, int> um;
                for (int i = 0; i < m; ++i) {
                    cur += sum[start][i];
                    if (cur == 0) {
                        vector<int> tmp(2);
                        tmp[0] = start;
                        tmp[1] = 0;
                        ans.push_back(tmp);
                        tmp[0] = start+len;
                        tmp[1] = i;
                        ans.push_back(tmp);
                        return ans;
                    }
                    if (um.find(cur) != um.end()) {
                        vector<int> tmp(2);
                        tmp[0] = start;
                        tmp[1] = um[cur]+1;
                        ans.push_back(tmp);
                        tmp[0] = start+len;
                        tmp[1] = i;
                        ans.push_back(tmp);
                        return ans;
                    }
                    um[cur] = i;
                }
            }
        }
        
        return ans;
    }
};
