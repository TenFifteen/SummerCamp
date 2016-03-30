/*
题目大意：
给定一个字符串，计算其hash code

解题思路：
见代码

遇到的问题：
没有考虑溢出。
*/
class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        int len = key.size();
        long long mul = 1, ans = 0;
        for (int i = len-1; i >= 0; --i) {
            ans += mul*key[i]; //may overflow
            mul *= 33;
            mul %= HASH_SIZE;
            ans %= HASH_SIZE;
        }
        return ans;
    }
};