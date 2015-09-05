/*
题目：58 % 落单的数 容易

题目大意：
给定一个数组，奇数个数。其中只有一个数出现了一次，其他的数都出现了两次。
求这个出现了一次的数

解题思路：
异或

遇到的问题：
没有问题。
太经典的问题了。
*/
class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int ans = 0;
        for (auto a : A) {
            ans ^= a;
        }
        return ans;
    }
};

