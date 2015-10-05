/*
题目：22 % 丢失的第一个正整数 中等

题目大意：
给定一个数组，问数组中缺少的第一个正整数是多少

解题思路：
将数字放到属于它的地方。

遇到的问题：
虽然思路中想到了原来做过的思路，但是还是有点不确定。还是不够扎实啊。
*/
class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == i+1) continue;
            int index = A[i]-1;
            while (index >= 0 && index < A.size()) {
                int tmp = A[index]-1;
                A[index] = index+1;
                if (tmp != index) {
                    index = tmp;
                } else {
                    break;
                }
            }
        }
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != i+1) {
                return i+1;
            }
        }
        return A.size()+1;
    }
};
