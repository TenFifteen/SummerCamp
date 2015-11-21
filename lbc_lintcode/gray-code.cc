/*
题目：33 % 格雷编码 中等

题目大意：
给定一个n，求n位的所有格雷码的数字，而且是按顺序输出。

解题思路：
两个动作交替进行。
1，变化最后一位
2，变化左后一个1左边的那位

遇到的问题：
不知道格雷码到底是怎么个变化规则，查了之前leetcode上的解法才想起来的。
*/
class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        int num = 0;
        int total = (1 << n);
        vector<int> ans(total);
        ans[0] = 0;
        bool last = true;
        for (int i = 1; i < total; ++i) {
            if (last) {
                if (num & 1) {
                    num -= 1;
                } else {
                    num += 1;
                }
            } else {
                int tmp = 1;
                while (!(num & tmp)) {
                    tmp <<= 1;
                }
                tmp <<= 1;
                if (num & tmp) {
                    num -= tmp;
                } else {
                    num += tmp;
                }
            }
            ans[i] = num;
            last = !last;
        }
        
        return ans;
    }
};
