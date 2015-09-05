/*
题目：39 % 落单的数 II 中等

题目大意：
给定一个数组，有3n+1个数，其中n个数都是出现了三次，只有一个数出现了一次，求出这个数

解题思路：
位操作

遇到的问题：
没有问题。
*/
class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int one = 0, two = 0, three = -1;
        for (auto a : A) {
            int add_one = three & a;
            int add_two = one & a;
            int add_three = two & a;
            three -= add_one;
            three += add_three;
            two -= add_three;
            two += add_two;
            one -= add_two;
            one += add_one;
        }
        return one;
    }
};
