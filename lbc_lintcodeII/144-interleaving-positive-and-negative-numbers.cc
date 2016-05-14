/*
题目大意：
给定一个数组，其中有正数和负数，现在要求把正数负数排序成间隔着的。

解题思路：
用下标替换的方式进行two points排序。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        int n = A.size();
        int posNum = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] > 0) posNum++;
        }
        
        #define arr(i) A[((i)*2+1)%(n|1)]
        
        if (posNum*2 > n) {
            // neg left, pos right
            int left = 0, right = n-1;
            while (left < right) {
                while (left < right && arr(left) < 0) left++;
                while (left < right && arr(right) > 0) right--;
                swap(arr(left), arr(right));
            }
        } else {
            // pos left, neg right
            int left = 0, right = n-1;
            while (left < right) {
                while (left < right && arr(left) > 0) left++;
                while (left < right && arr(right) < 0) right--;
                swap(arr(left), arr(right));
            }
        }
    }
};
