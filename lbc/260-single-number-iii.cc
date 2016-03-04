/*
题目大意：
给定一个数组，其中除了两个数字之外，其他所有数字都是出现了两次。只有这两个数字出现了一次。
求这两个数字

解题思路：
将所有数字都异或一遍，可以得到a^b。
然后用这个结果的最后一个为1的bit来讲所有的数字分为两种，然后其中一种包含a，另一种包含b。
所以可以用异或的方式找到该数字。

遇到的问题：
没有问题。
这个题目是编程之美里面的题目，想了好一会才想起来的。

再次阅读：
经典老题，没有问题。
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int axorb = 0;
        for (auto n : nums) {
            axorb ^= n;
        }
        
        int one = axorb & (axorb-1);
        if (one != 0) {
            one ^= axorb;
        }
        
        vector<int> ans(2, 0);
        for (auto n : nums) {
            if (n & one) {
                ans[0] ^= n;
            } else {
                ans[1] ^= n;
            }
        }
        
        return ans;
    }
};
/*
第二次做：
经典老题。
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto n : nums) x ^= n;
        
        x -= (x & (x-1));
        
        int a = 0, b = 0;
        for (auto n : nums) {
            if (n & x) a ^= n;
            else b ^= n;
        }
        
        vector<int> ans(2);
        ans[0] = a;
        ans[1] = b;
        return ans;
    }
};