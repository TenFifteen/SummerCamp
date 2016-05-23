/*
题目大意：
给定一个数组，表示小朋友的身高，要求每个人至少一个糖果；另外比邻居高，则一定要
糖果也比邻居多。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        // Write your code here
        if (ratings.size() == 0) return 0;
        
        vector<int> ans(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                ans[i] = ans[i-1] + 1;
            }
        }
        
        for (int i = ratings.size()-1; i > 0; --i) {
            if (ratings[i-1] > ratings[i]) {
                ans[i-1] = max(ans[i] + 1, ans[i-1]);
            }
        }
        
        int total = 0;
        for (auto a : ans) total += a;
        return total;
    }
};
