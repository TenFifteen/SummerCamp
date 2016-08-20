/*
题目大意：
给定一个数组，其中任意相邻的两个数字都不同。求出峰值元素的下标。峰值元素有很多，求其中任意一个就行。

解题思路：
二分查找。

遇到的问题：
一次通过。

再次阅读：
二分。
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)return 0;
        if(nums[0] > nums[1])return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2])return nums.size()-1;
        int left = 1, right = nums.size()-2;
        while(left < right){
            int mid = left + (right-left+1)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])return mid;
            if(nums[mid] < nums[mid-1])right = mid-1;
            else left = mid+1;
        }
    }
};
/*
第二次做：
这次比较失败，首先是把返回值类型搞错了，应该是返回的下标。
另外就是二分写起来竟然出现了left = mid right = mid这种不彻底的写法。
二分的写法一定要注意有终止条件。
所以能用mid-1或者mid+1这种形式，就用这种。要不然至少有一个用这个。
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        assert(nums.size() > 0);

        if (nums.size() == 1) return 0;

        int n = nums.size();
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;

        int left = 1, right = n-2;
        while (left < right) {
            int mid = (left+right) >> 1;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            if (nums[mid] <= nums[mid-1]) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};
/*
 * ok
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums.back() > nums[nums.size()-2]) return nums.size()-1;

        int left = 1, right = nums.size()-2;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            if (nums[mid] < nums[mid-1]) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};
