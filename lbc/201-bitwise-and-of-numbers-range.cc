/*
题目大意：
给定一个区间，将其中所有的数字都and一下

解题思路：
由于只要有个位上曾经出现过0，那么这个位就是0.
所以如果两个数字的长度不同，就是0
另外，就是从前往后找，将所有相同的bit加进去

遇到的问题：
一开始没有考虑到len位0的情况
另外就是没有注意到==优先级比&优先级还要高
还有就是一开始只考虑两个数字前面的1了，没有考虑0
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int lenM = bitLen(m);
        int lenN = bitLen(n);
        if(lenM != lenN)return 0;
        if(m == 0)return 0;
        int ret = 0;
        int i = (1 << (lenM-1));
        while((i&m) == (i&n) && i){
            if(i&m)ret += i;
            i >>= 1;
        }
        return ret;
    }
    
    int bitLen(int x){
        int ret = 0;
        while(x){
            ret++;
            x >>= 1;
        }
        return ret;
    }
};