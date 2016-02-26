/*
题目大意：
给两个01的字符串。将其相加。

解题思路：
直接做就是了，类似于大整数。

遇到的问题：
一次通过。

再次阅读：
首先还是余数用carry的问题。
另外，我感觉我的解法没啥太大问题，但是如果需要考虑string的开销的话，可以提前申请号string的空间。
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int index_a = a.size()-1;
        int index_b = b.size()-1;
        int yu = 0;
        while(index_a >= 0 || index_b >= 0 || yu){
            if(index_a >= 0){
                yu += a[index_a--]-'0';
            }
            if(index_b >= 0){
                yu += b[index_b--]-'0';
            }
            ans.push_back('0'+yu%2);
            yu /= 2;
        }
        for(int i = 0; i < ans.size()/2; ++i){
            swap(ans[i], ans[ans.size()-1-i]);
        }
        return ans;
    }
};
/*
第二次做：
这次做的还算是顺利，不过在使用一个小聪明的时候，反而被小聪明给wa了。
就是下面用了&和移位来提高运行速度。结果竟然+的优先级比&要高，所以结果是错误的。
*/
class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "") return b;
        if (b == "") return a;
        
        int ia = a.size()-1, ib = b.size()-1;
        int carry = 0;
        string ans;
        
        while (ia >= 0 || ib >= 0) {
            if (ia >= 0) carry += a[ia--]-'0';
            if (ib >= 0) carry += b[ib--]-'0';
            ans.push_back((carry & 0x1) + '0');
            carry >>= 1;
        }
        
        if (carry) ans.push_back('1');
        
        for (int i = 0; i < ans.size()/2; ++i) {
            swap(ans[i], ans[ans.size()-1-i]);
        }
        
        return ans;
    }
};