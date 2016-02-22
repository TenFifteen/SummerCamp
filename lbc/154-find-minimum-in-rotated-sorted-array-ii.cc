/*
题目大意：
给定一个数组，本来排序，现在是旋转了一下。跟153题是一样的，但是数字有重复。

解题思路：
经过分析，就算是二分，也不可以降到logn，所以是n的算法。
所以直接遍历一遍就行了。

遇到的问题：
一次通过。

再次阅读：
虽然这种情况下是一个渐进复杂度是n的算法，但是直接用这种简单思路还是有点傻逼的。
看一下DISCUSS中最好的解答：
这样的话，可以大幅度的提高搜索速度。尤其是在重复量比较小的时候。
class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size() - 1;
        int mid = 0;

        while(lo < hi) {
            mid = lo + (hi - lo) / 2;

            if (num[mid] > num[hi]) {
                lo = mid + 1;
            }
            else if (num[mid] < num[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return num[lo];
    }
};
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ret = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < ret)ret = nums[i];
        }
        return ret;
    }
};