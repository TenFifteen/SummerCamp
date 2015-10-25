/*
题目：22 % Copy Books 困难

题目大意：
给定n个书以及页数。然后有k个人来抄写这些书，每个人分得的数必须是连续的。
问最短需要多少时间可以抄完所有的书

解题思路：
一开始就是想到的动态规划，但是具体怎么优化到nk实在是不知道怎么处理
然后看了别人的代码，感觉意思其实自己也想到了，就是不知道怎么写。
或者说就是不知道这种情况到底应该怎么优化。
具体情况，见代码

遇到的问题：
还有人用二分的方法。可以让复杂度到nlogC，C是所有书的总页数。我觉得思路也是挺好的。
学到了partial_sum这个标准函数。
*/
class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        if (k >= pages.size()) {
            int ret = pages[0];
            for (int i = 1; i < pages.size(); ++i) {
                ret = max(ret, pages[i]);
            }
            return ret;
        }
        vector<vector<int>> dp(k, vector<int>(pages.size(), INT_MAX));
        partial_sum(pages.begin(), pages.end(), dp[0].begin());
        for (int i = 1; i < k; ++i) {
            dp[i][i] = max(dp[i-1][i-1], pages[i]);
            int left = i-1;
            int right = i+1;
            while (right < pages.size()) {
                int part = dp[0][right] - dp[0][left];
                dp[i][right] = min(dp[i][right], max(dp[i-1][left], part));
                if (left < right && part > dp[i-1][left]) {
                    left++;
                } else {
                    right++;
                    if (left > i-1) {
                        left--;
                    }
                }
            }
        }
        return dp[k-1][pages.size()-1];
    }
};
