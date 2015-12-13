/*
题目大意：
找到第n个丑数。

解题思路：
在已有k个丑数的前提下，找第k+1个丑数的方式：
分别找到乘以2、3、5三个数组成的最小的那个丑数，然后就是这个丑数了。

遇到的问题：
这个题目是在编程之美中看到的。竟然现在就用到了。

*/
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        
        set<int> s;
        s.insert(1);
        
        for (int i = 1; i < n; ++i) {
            int next = *s.rbegin() + 1;
            int tmp = *s.lower_bound((next+1)/2) * 2;
            tmp = min(tmp, *s.lower_bound((next+2)/3) * 3);
            tmp = min(tmp, *s.lower_bound((next+4)/5) * 5);
            
            s.insert(tmp);
        }
        
        return *s.rbegin();
    }
};