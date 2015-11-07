/*
题目：32 % 分糖果 困难

题目大意：
给定一个数组，表示一排小孩的权值。现在要给小孩分糖果，每个人至少一个。
相邻的小孩，权值高的要比权值低的糖果多，问最少要分多少糖果？

解题思路：
贪心。
从左往右贪心一遍，从右往左贪心一遍。
因为相邻的小孩只有三种情况，如果左边的大，那么右往左遍历的生效；
如果右边的大，那么左往右遍历的生效；
相等，随便。
然后可以证明，取两遍遍历的最大值，就可以满足题目条件。

遇到的问题：
没有问题。
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
        if (ratings.size() == 1) return 1;
        vector<int> left(ratings.size(), 1);
        vector<int> right(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                left[i] = left[i-1]+1;
            }
        }
        for (int i = ratings.size()-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                right[i] = right[i+1]+1;
            }
        }
        int ret = 0;
        for (int i = 0; i < ratings.size(); ++i) {
            ret += max(left[i], right[i]);
        }
        return ret;
    }
};
