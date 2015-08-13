/*
题目大意：
给定一个数字，然后不断的用其各位数字的平方和来替代它。如果最后它变成了1，那么就是happy的，
要不然就是会循环下去，那就是not happy的。

解题思路：
用一个set记录已经访问过的数字

遇到的问题：
一次通过。
*/
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        while(n != 1){
            if(us.find(n) != us.end())return false;
            us.insert(n);
            n = getBitSquare(n);
        }
        return true;
    }
    
    int getBitSquare(int n){
        int ret = 0;
        while(n){
            int cur = n % 10;
            ret += cur * cur;
            n /= 10;
        }
        return ret;
    }
};