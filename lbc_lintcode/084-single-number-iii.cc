/*
题目：33 % 落单的数 III 中等

题目大意：
给定n*2+2个数的数组，其中n个数都是出现了两次，有2个数出现了一次，求这两个数

解题思路：
首先得到两个数的异或，然后根据该值的最后一位将数组的数分为两部分，分别求a和b

遇到的问题：
没想到

精彩解答：
http://www.wengweitao.com/lintcode-single-number-i-ii-iii-luo-dan-de-shu.html
*/
class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int a_and_b = 0;
        for (auto a : A) {
            a_and_b ^= a;
        }
        a_and_b -= a_and_b & (a_and_b-1);
        int a = 0, b = 0;
        for (auto x : A) {
            if (x & a_and_b) {
                a ^= x;
            } else {
                b ^= x;
            }
        }
        vector<int> ans(2);
        ans[0] = a;
        ans[1] = b;
        return ans;
    }
};
