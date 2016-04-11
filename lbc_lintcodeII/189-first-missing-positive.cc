/*
题目大意：
给定一个数组，找到该数组中第一个没有出现的正数。

解题思路：
见代码 。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        if (A.size() == 0) return 1;
        
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == i+1 || A[i] <= 0) continue;
            
            int now = A[i];
            A[i] = -1;
            while (now > 0 && now <= A.size()) {
                if (A[now-1] == now) break;
                int tmp = A[now-1];
                A[now-1] = now;
                now = tmp;
            }
        }
        
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != i+1) return i+1;
        }
        return A.size()+1;
    }
};