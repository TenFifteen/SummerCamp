/*
题目大意：
给定一个k，一个n。
问从0到n中，有多少个k字母出现过。

解题思路：
数学思路。

遇到的问题：
有三个主要的问题：
1，后面有%0的风险，所以需要避免。
2，如果k==0，那么第一位的计算应该略过
3，如果n==0，而且k==0，那么应该直接返回。
*/
class Solution {
    int getLength(int x) {
        int len = 0;
        while (x) {
            len++;
            x /= 10;
        }
        return len;
    }
    
    int oneMul(int x) {
        int ret = 1;
        for (int i = 0; i < x; ++i) ret *= 10;
        return ret;
    }
    
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        if (k == n && n == 0) return 1; // special case
        
        int len = getLength(n);
        int mul = oneMul(len-1), left = 0, right = n%mul, ans = 0;
        for (int i = 1; i <= len; ++i) {
            int digit = n / mul;
            
            if (i == 1 && k == 0) { // to prevent 0 goes first
                mul /= 10;
                left *= 10;
                left += digit;
                n = right;
                right = n%mul;
                continue;
            }
            
            
            if (digit < k) {
                ans += left*mul;
            } else if (digit == k) {
                ans += left*mul + right + 1;
            } else {
                ans += (left+1)*mul;
            }
            
            if (i == len) break; // to prevent from mul == 0 and n%mul
            mul /= 10;
            left *= 10;
            left += digit;
            n = right;
            right = n%mul;
        }
        
        return ans;
    }
};