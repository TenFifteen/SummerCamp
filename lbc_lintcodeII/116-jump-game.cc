/*
题目大意：
给定一个数组，每个位置表示可以跳多远。问能否从第一个位置跳到最后一个位置。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        if (A.size() < 2) return true;
        if (A[0] == 0) return false;
        
        int cur = 0, len = A[0];
        while (len < A.size()-1) {
            int next = len;
            for (int i = cur; i <= len; ++i) {
                next = max(i+A[i], next);
            }
            
            if (next == len) return false;
            cur = len+1;
            len = next;
        }
        
        return true;
    }
};
