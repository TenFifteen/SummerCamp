/*
题目大意：
给定一个数，定义其happy number是所有digit的平方和。
如果一个数最后的happy number收敛到了1，则快乐的。否则是不快乐的。

解题思路：
直接模拟。

遇到的问题：
没有。
*/
class Solution {
    int nextHappy(int n) {
        int ret = 0;
        
        while (n) {
            int digit = n%10;
            n /= 10;
            ret += digit*digit;
        }
        
        return ret;
    }
    
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        if (n == 1) return true;
        
        unordered_set<int> hash;
        while (n != 1) {
            if (hash.find(n) != hash.end()) return false;
            hash.insert(n);
            n = nextHappy(n);
        }
        
        return true;
    }
};