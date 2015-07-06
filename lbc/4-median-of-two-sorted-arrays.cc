/*
题目大意：
有两个排好序的数组，数组的长度不一定相等。然后找出两个数组的总体的中位数，如果是偶数，则返回两个中间的数的平均值

解题思路：
对于寻找中位数来讲，可以简化为寻找第k大的数。如果原来total是奇数，那么就是返回第total/2+1小的数；如果total是偶数，
那么就是返回第total/2 和total/2+1小的两个数的平均值。

遇到的问题：
这个题目原来就没有思路，感觉好难。一开始想的是跟两个等长数组中寻找中位数的题差不多，采用二分的方法进行寻找。但是感觉
实现起来实在是太难了，一直没有想到怎么实现出来，各种边界情况实在是复杂。
上网找了别人的解法，感觉转化为寻找第k小的数之后，明显有了统一的解法了。而且，对于寻找两个数组中第k小的数的那个函数，
也是有很多需要注意的地方。

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(total % 2){
            return findKMin(nums1,0,nums2,0,total/2+1);
        }else{
            return (findKMin(nums1,0,nums2,0,total/2) + findKMin(nums1,0,nums2,0,total/2+1))/2;
        }
    }
    
    double findKMin(vector<int> &nums1, int head1, vector<int> &nums2, int head2, int k){
        int len1 = nums1.size()-head1;
        int len2 = nums2.size()-head2;
        if(len1 > len2){
            return findKMin(nums2,head2,nums1,head1,k);
        }
        if(len1 == 0){
            return nums2[head2+k-1];
        }
        if(k == 1){
            return min(nums1[head1], nums2[head2]);
        }
        int k1 = min(k/2,len1);
        int k2 = k - k1;
        int m1 = nums1[head1+k1-1];
        int m2 = nums2[head2+k2-1];
        if(m1 == m2){
            return m1;
        }else if(m1 < m2){
            return findKMin(nums1,head1+k1,nums2,head2,k-k1);
        }else{
            return findKMin(nums1,head1,nums2,head2+k2,k-k2);
        }
    }
};