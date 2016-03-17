/*
题目大意：
给定一个数组，其中除了一个数字出现了一次之外，其他的数字都出现了三次。
问该数字是什么？

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int one = 0, two = 0;
        for (auto a : A) {
            one ^= a & ~two;
            two ^= a & ~one;
        }
        return one;
    }
};