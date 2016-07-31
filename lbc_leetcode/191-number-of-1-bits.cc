/*
题目大意：
给定一个无符号整数，求其中为1的位的个数

解题思路：
利用n & -n获得最后一个为1的bit

遇到的问题：
没有问题，一次通过

再次阅读：
也是一个经典老题了，感觉之前这种做法已经非常好了。
但是ICS里还有一种更好的：
int hammingWeight(uint32_t n)
{
    n = (n & 0x55555555) + (n >>  1 & 0x55555555); // put count of each  2 bits into those  2 bits
    n = (n & 0x33333333) + (n >>  2 & 0x33333333); // put count of each  4 bits into those  4 bits
    n = (n & 0x0F0F0F0F) + (n >>  4 & 0x0F0F0F0F); // put count of each  8 bits into those  8 bits
    n = (n & 0x00FF00FF) + (n >>  8 & 0x00FF00FF); // put count of each 16 bits into those 16 bits
    n = (n & 0x0000FFFF) + (n >> 16 & 0x0000FFFF); // put count of each 32 bits into those 32 bits
    return n;
}
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n){
            ret++;
            n -= n & -n;
        }
        return ret;
    }
};
/*
第二次做：
ICS方法做的，很好。
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
    }
};
/*
 * it's good
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        return n;
    }
};
