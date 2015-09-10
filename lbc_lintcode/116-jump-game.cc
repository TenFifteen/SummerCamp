/*
题目：39 % 跳跃游戏 中等

题目大意：
给定一个数组，表示每个数字表示从该位置最远可以往前跳多远。问，从起点开始，是否可以跳到最后

解题思路：
贪心

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        if (A.size() == 0) return false;
        if (A.size() == 1) return true;
        int dist = 0;
        int cur = 0;
        while (dist < A.size()-1) {
            int newdist = dist;
            for (int i = cur; i <= dist; ++i) {
                newdist = max(newdist, A[i]+i);
            }
            if (newdist == dist) return false;
            cur = dist+1;
            dist = newdist;
        }
        return true;
    }
};

