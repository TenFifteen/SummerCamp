/*
题目大意：
给定2*n+1个数，其中n个数都出现了两次，只有一个数出现了一次。找出来。

解题思路：
太经典了。

遇到的问题：
没有。
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
        for (auto a : A) ans ^= a;
        return ans;
    }
};
