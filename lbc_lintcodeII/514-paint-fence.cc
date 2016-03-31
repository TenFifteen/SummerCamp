/*
题目大意：
给定一排栏杆，k中颜色。给栏杆涂颜色，要求是连续的颜色不能超过两个。

解题思路：
动归，见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        if (k == 0) return 0;
        if (k == 1) return n < 3 ? 1 : 0;
        
        int same = 0, diff = k;
        for (int i = 1; i < n; ++i) {
            int newDiff = (same+diff)*(k-1);
            same = diff;
            diff = newDiff;
        }
        
        return same + diff;
    }
};