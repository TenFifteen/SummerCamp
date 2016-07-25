/*
题目大意：
给定一个三角，求出从头到底的最小的路径。

解题思路：
动态规划。

遇到的问题：
一些边界问题。

再次阅读：
虽然我这种做法的时间和空间复杂度都已经达到了最优的要求，但是总是觉得有些啰嗦。
然后就在DISCUSS中看到了下面这种解法，实在是精妙啊。从下往上走，既可以免去了空间
使用了两个vector，又可以免去了最后一次找最大值的过程。
int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();
    vector<int> minlen(triangle.back());
    for (int layer = n-2; layer >= 0; layer--) // For each layer
    {
        for (int i = 0; i <= layer; i++) // Check its every 'node'
        {
            // Find the lesser of its two children, and sum the current value in the triangle with it.
            minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i];
        }
    }
    return minlen[0];
}
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> ans(triangle.size()), last(triangle.size());
        if(triangle.size() == 0)return 0;
        last[0] = triangle[0][0];
        ans[0] = last[0];
        for(int i = 1; i < triangle.size(); ++i){
            ans[0] = last[0] + triangle[i][0];
            for(int j = 1; j < i; ++j){
                ans[j] = min(last[j], last[j-1]) + triangle[i][j];
            }
            ans[i] = last[i-1] + triangle[i][i];
            last = ans;
        }
        int ret = ans[0];
        for(int i = 1; i < ans.size(); ++i){
            if(ans[i] < ret){
                ret = ans[i];
            }
        }
        return ret;
    }
};
/*
第二次做：
简单题，不过还是写错了两个地方，一个是把i--写成了i++；
一个是把min写成了max。
一个是写作惯性，没有用心；一个是审题不用心。

另外一个很值得注意的地方就是vector的back和front方法。以前都是只会用begin和end，
所以每次写出来取最后一个元素的代码都不好看。感觉有了这两个方法之后，取首尾元素方便多了。
而且front和back取出来是元素类型，而不是指针。
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;

        int n = triangle.size();
        vector<int> ans(triangle[triangle.size()-1]);
        for (int i = n-2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                ans[j] = min(ans[j], ans[j+1]) + triangle[i][j];
            }
        }

        return ans[0];
    }
};
/*
 * some easy
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        vector<int> dp(triangle.size());
        dp[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            dp[i] = dp[i-1] + triangle[i][i];
            for (int j = i-1; j > 0; --j) {
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }

        int ans = INT_MAX;
        for (auto d : dp) ans = min(d, ans);
        return ans;
    }
};
