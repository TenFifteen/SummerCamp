/*
题目大意：
一个排序的数组，从某个位置偏移了，类似于4560123这样子。给定一个target，找出其index，
或者没有就返回-1.

解题思路：
就是二分搜索，不过在确定下一次的搜索边界的时候，一定要注意这是一个rotate的排序数组就好了。

遇到的问题：
本来觉得这个问题好难的。可以竟然一次通过了。
不过题目中的各种条件还是要注意一下的。

再次阅读：
看到这个题目，一看就知道是二分。然后看了之前的代码，虽然有点啰嗦，但是逻辑上是没有问题的。
然后看了一下DISCUSS，竟然还真有不一样的思路，他们是先找出数组的最小值，也就是数组的拐点，
然后再进行二分搜索。
class Solution {
public:
    int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};
不过，我觉得他这个方法可以写的再好一点。
就是将二分查找封装为一个函数，然后对两段分开进行二分搜索。
我觉得那样的代码比较好一些。
不过他这种自己处理拐点的用法，还是挺厉害的。感觉有点难以理解啊。
仔细想了一下，它这个的方法的含义应该是整个数组往右移了rot个位置，所以每个数字的真实的位置应该是往右
移动了rot位，当超过了n的时候，就需要去一下mod。嗯，如此看来，这种写法实在是挺精妙的。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (right-left)/2 + left;
            if(nums[mid] == target)return mid;
            if(nums[mid] < target){
                if(nums[right] > nums[mid]){
                    if(nums[right] >= target){
                        left = mid+1;
                    }else{
                        right = mid-1;
                    }
                }else{
                    left = mid+1;
                }
            }else{
                if(nums[right] > nums[mid]){
                    right = mid-1;
                }else{
                    if(nums[left] <= target){
                        right = mid-1;
                    }else{
                        left = mid+1;
                    }
                }
            }
        }
        return -1;
    }
};
/*
第二次做：
这次的代码跟之前写的代码竟然非常的相似。。
虽然是有一点点啰嗦，不过这代表了解题思路，没有任何的化简过程。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[right] < nums[left]) {//has pivot
                if (nums[mid] >= nums[left]) {//left half
                    if (nums[mid] > target && nums[left] <= target) {
                        right = mid-1;
                    } else {
                        left = mid+1;
                    }
                } else {//right half
                    if (nums[mid] < target && nums[right] >= target) {
                        left = mid+1;
                    } else {
                        right = mid-1;
                    }
                }
            } else {//is sorted
                if (nums[mid] < target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        
        return -1;
    }
};