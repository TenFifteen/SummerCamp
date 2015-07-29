/*
题目大意：
给定两个数组，将其合并到数组1中。都是排序的。

解题思路：
申请一块m+n的空间，将其归并到该区间中。然后再拷贝回num1.

遇到的问题：
本来以为这道题目需要原地归并，不能申请空间呢。结果试了一下，竟然通过了。
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(m+n);
        int p1 = 0, p2 = 0, p3 = 0;
        while(p1 < m && p2 < n){
            if(nums1[p1] < nums2[p2]){
                tmp[p3++] = nums1[p1++];
            }else{
                tmp[p3++] = nums2[p2++];
            }
        }
        if(p1 == m){
            while(p3 < m+n){
                tmp[p3++] = nums2[p2++];
            }
        }else{
            while(p3 < m+n){
                tmp[p3++] = nums1[p1++];
            }
        }
        for(int i = 0; i < m+n; ++i){
            nums1[i] = tmp[i];
        }
    }
};