/*
题目大意：
建堆

解题思路：
见代码。

遇到的问题：
建堆的时候从后往前建。O(n)的复杂度。
*/
class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        if (A.size() < 2) return;
        
        int n = A.size();
        for (int i = n/2; i >= 0; --i) {
            int cur = i;
            while (true) {
                int left = cur*2+1, right = left+1;
                int minIndex = cur;
                if (left < n && A[left] < A[minIndex]) minIndex = left;
                if (right < n && A[right] < A[minIndex]) minIndex = right;
                
                if (minIndex == cur) break;
                swap(A[cur], A[minIndex]);
                cur = minIndex;
            }
        }
    }
};
