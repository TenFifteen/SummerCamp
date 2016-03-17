/*
题目大意：
实现atoi

解题思路：
看了一下atoi函数的要求才开始实现的。

遇到的问题：
没有太大问题。就是忘记了更新i了。。
*/
class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        int i = 0;
        while (i < str.size() && str[i] == ' ') i++;
        
        if (i == str.size()) return 0;
        
        bool neg = false;
        if (str[i] == '-') {
            neg = true;
            i++;
        } else if (str[i] == '+') i++;
        
        if (i == str.size() || str[i] < '0' || str[i] > '9') return 0;
        
        int ans = 0;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            int next = ans * 10;
            
            if (neg) {
                next -= str[i]-'0';
                if (next/10 != ans) return INT_MIN;
            } else {
                next += str[i]-'0';
                if (next/10 != ans) return INT_MAX;
            }
            
            ans = next;
            i++;
        }
        return ans;
    }
};