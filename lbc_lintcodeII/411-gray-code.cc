/*
题目大意：
求格雷码。

解题思路：
见代码。

遇到的问题：
还是没有记清楚具体什么规则。
另外就是==的优先级竟然比&的优先级高。。。难以想象
*/
class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        if (n < 0) return vector<int>();
        if (n == 0) return vector<int>(1, 0); // don't know why
        
        int total = 1 << n;
        vector<int> ans(total);
        ans[1] = 1;
        int i = 2;
        while (i < total) {
            int last = ans[i-1];
            int mask = 1;
            while ((last & mask) == 0) mask <<= 1; // it turns out that == priority bigger than &
            mask <<= 1;
            
            ans[i] = last ^ mask;
            ans[i+1] = ans[i] ^ 0x1;
            i += 2;
        }
        
        return ans;
    }
};
