/*
题目大意：
给定一个n，问小于n的数里面有多少个素数

解题思路：
筛选法找素数

遇到的问题：
一开始当做了小于等于n了。

再次阅读：
简单的找素数的代码。
之前用的是筛法找素数，感觉代码还是很好的了。
然后看了一下DISCUSS，也就是这样了。
*/
class Solution {
public:
    int countPrimes(int n) {
        vector<int> flag(n, true);
        int ret = 0;
        for(int i = 2; i < n; ++i){
            if(flag[i]){
                ret++;
                for(int j = i; j < n; j += i){
                    flag[j] = false;
                }
            }
        }
        return ret;
    }
};