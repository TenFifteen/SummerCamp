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

再次阅读：
感觉一开始看到这道题目，不是很有清晰的思路，看了之前的代码，感觉想法还是很好的。
然后又看了一下DISCUSS，有一个也挺不错的代码：
int rangeBitwiseAnd(int m, int n) {
    return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
}
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
/*
第二次做：
比较好。唯一一点就是又没有注意到==的优先级比&的优先级高。
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) return m;
        
        int mask = INT_MIN;
        while ((mask & m) == (mask & n)) {
            mask >>= 1;
        }
        
        return m & (mask << 1);
    }
};