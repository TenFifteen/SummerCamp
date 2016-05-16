/*
题目大意：
计算所有的逆序对

解题思路：
归并排序的思路做。

遇到的问题：
没有。
*/
class Solution {
    long long mergeSort(vector<int> &A, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right-left)/2;
        long long ret = 0;
        
        ret += mergeSort(A, left, mid);
        ret += mergeSort(A, mid+1, right);
        
        vector<int> tmp(A.begin()+left, A.begin()+right+1);
        int i = 0, j = mid-left+1, k = left;
        while (i <= mid-left && j <= right-left) {
            if (tmp[i] <= tmp[j]) A[k++] = tmp[i++];
            else {
                ret += (mid-left-i+1);
                A[k++] = tmp[j++];
            }
        }
        
        while (i <= mid-left) A[k++] = tmp[i++];
        
        return ret;
    }
    
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        if (A.size() < 2) return 0;
        return mergeSort(A, 0, A.size()-1);
    }
};
