/*
题目：24 % 带重复元素的子集 中等

题目大意：
给定一个有重复元素的集合，求出所有的组合

解题思路：
用到了dfs和深度的概念

遇到的问题：
本来这个题目是leetcode中的原题，可是到了这里还是没有自己写出来，看来这种利用树的深度的概念，
还是不是很熟练啊。
回头要参考leetcode上的代码
*/
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<vector<int>> ans;
        if (S.size() == 0) return ans;
        vector<int> SS(S);
        sort(SS.begin(), SS.end());
        vector<int> cur;
        sub(ans, SS, cur, 0);
        return ans;
    }

    void sub(vector<vector<int>> &ans, const vector<int> &S, vector<int> &cur, int index) {
        ans.push_back(cur);
        for (int i = index; i < S.size(); ++i) {
            if (i != index && S[i] == S[i-1]) continue;
            cur.push_back(S[i]);
            sub(ans, S, cur, i+1);
            cur.pop_back();
        }
    }
};

