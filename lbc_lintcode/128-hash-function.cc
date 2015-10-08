/*
题目：15 % 哈希函数 容易

题目大意：
给定一个hash的规则，实现其函数。

解题思路：
直接做，注意溢出

遇到的问题：
一定要注意溢出的问题。
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
        long long ret = 0;
        long long cur = 1;
        for (int i = key.size()-1; i >= 0; --i) {
            long long tmp = key[i] * cur;
            ret += tmp;
            ret %= HASH_SIZE;
            cur *= 33;
            cur %= HASH_SIZE;
        }
        return ret;
    }
};
