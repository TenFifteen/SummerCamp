/*
题目大意：
给定两个数组，将其合并到数组1中。都是排序的。

解题思路：
申请一块m+n的空间，将其归并到该区间中。然后再拷贝回num1.

遇到的问题：
本来以为这道题目需要原地归并，不能申请空间呢。结果试了一下，竟然通过了。

再次阅读：
这次第一想法已经知道了原地归并怎么做了。
就是从后往前归并。
如下：
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i=m-1;
        int j=n-1;
        int k = m+n-1;
        while(i >=0 && j>=0)
        {
            if(A[i] > B[j])
                A[k--] = A[i--];
            else
                A[k--] = B[j--];
        }
        while(j>=0)
            A[k--] = B[j--];
    }
};
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
/*
第二次做：
简单题，一次通过。
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m-1, i2 = n-1, i = m+n-1;
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] > nums2[i2]) {
                nums1[i--] = nums1[i1--];
            } else {
                nums1[i--] = nums2[i2--];
            }
        }
        while (i2 >= 0) nums1[i--] = nums2[i2--];
    }
};
/*
 * some easy
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m-1, i2 = n-1, i3 = m+n-1;
        while (i1 >= 0 || i2 >= 0) {
            if (i1 < 0) nums1[i3--] = nums2[i2--];
            else if (i2 < 0) nums1[i3--] = nums1[i1--];
            else if (nums1[i1] > nums2[i2]) nums1[i3--] = nums1[i1--];
            else nums1[i3--] = nums2[i2--];
        }
    }
};
