/*
题目：33 % 跳跃游戏 II 中等

题目大意：
给定一个数组，每个数字表示当前位置可以往前跳多远。
问从最开始，用最少多少次跳跃可以到大最后。

解题思路：
贪心。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        if (A.size() < 2) return 0;
        int cnt = 1;
        int cur = 0;
        while (cur < A.size()-1) {
            int next = 0;
            int max = 0;
            if (cur + A[cur] >= A.size()-1) return cnt;
            for (int i = cur+1; i <= cur+A[cur]; ++i) {
                if (A[i] + i > max) {
                    max = A[i] + i;
                    next = i;
                }
            }
            cnt++;
            cur = next;
        }
        return cnt;
    }
};
