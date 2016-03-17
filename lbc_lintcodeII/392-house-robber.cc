/*
题目大意：
抢劫房屋的最大值，相邻的房屋不可以抢劫。

解题思路：
动归

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        long long rob = 0, norob = 0;
        for (auto a : A) {
            long long newrob = max(rob, norob+a);
            norob = max(norob, rob);
            rob = newrob;
        }
        return max(rob, norob);
    }
};