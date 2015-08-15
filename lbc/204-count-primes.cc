/*
题目大意：
给定一个n，问小于n的数里面有多少个素数

解题思路：
筛选法找素数

遇到的问题：
一开始当做了小于等于n了。
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