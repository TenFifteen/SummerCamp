/*
题目大意：
两个字符串表示的二进制数的加法。

解题思路：
直接加

遇到的问题：
问题主要是string初始化方法里面没有直接只指定数量的构造函数。
*/
class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        if (a == "") return b;
        if (b == "") return a;
        
        string ans(max(a.size(), b.size())+1, 0);
        int ia = a.size()-1, ib = b.size()-1, ic = ans.size()-1, carry = 0;
        while (ia >= 0 || ib >= 0) {
            if (ia >= 0) carry += a[ia--]-'0';
            if (ib >= 0) carry += b[ib--]-'0';
            ans[ic--] = carry % 2 + '0';
            carry /= 2;
        }
        
        if (carry) {
            ans[ic--] = carry + '0';
        }
        
        return ans.substr(ic+1);
    }
};