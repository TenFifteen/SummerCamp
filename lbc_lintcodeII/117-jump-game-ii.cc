/*
题目大意：
给定一个数组，每个数字表示可以跳的最远的距离。问最少多少次跳跃可以到达末尾。

解题思路：
见代码。

遇到的问题：
没有。
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
        
        int cur = 0, len = A[0], steps = 1;
        while (len < A.size()-1) {
            int next = len;
            for (int i = cur; i <= len; ++i) {
                next = max(next, i+A[i]);
            }
            
            if (next == len) return -1;
            cur = len+1;
            len = next;
            steps++;
        }
        
        return steps;
    }
};