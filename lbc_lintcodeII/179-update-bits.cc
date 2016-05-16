/*
题目大意：
用ｍ的一段二进制bit替换n的一段二进制。

集体思路：
见代码。

遇到的问题：
如果移位数量超过了31，那么结果就是移位x%32位。
但是如果是用的常数进行移位，编译器会给出警告，但是编译器还是知道你想做什么事情的，
所以编译器会给你移位32以上，最后结果就是0.
所以被编译器骗了好一会才想起这件事情。
*/
class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        if (j == 31) n &= ~(0xffffffff << i);
        else n &= ((0xffffffff << (j+1)) | ~(0xffffffff << i));
        n |= m << i;
        return n;
    }
};
