/*
题目：丑数 中等

题目大意：
定义丑数是只含有3、5、7三个因子的数，问第k个丑数是多少

解题思路：
如果一个一个的判断该数是否是丑数，复杂度较高，但是不需要额外的空间
如果是将k个丑数都按序存起来，那么可以将当前的可以扩展的最小的丑数加入到序列尾部
时间和空间复杂度都是k的。

遇到的问题：
一开始没想到这种思路，只是想到了第一种。
第二种虽然是想这么扩展来着，但是没想到怎么找到当前应该扩展的最小的那个数
这个题目据说原来是google的一道面试题，然后丑数的定义可以有很多种。比如，2，3，5
*/
class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        vector<long long> ans(k);
        ans[0] = 3;
        ans[1] = 5;
        ans[2] = 7;
        int index1 = 0, index2 = 0, index3 = 0;
        for (int i = 3; i < k; ++i) {
            while(ans[index1] * 3 <= ans[i-1])index1++;
            while(ans[index2] * 5 <= ans[i-1])index2++;
            while(ans[index3] * 7 <= ans[i-1])index3++;
            ans[i] = min(min(ans[index1]*3, ans[index2]*5), ans[index3]*7);
        }
        return ans[k-1];
    }
};
