/*
题目大意：
给定一个数组，寻找第k大的数

解题思路：
用快排思想

遇到的问题：
我一直以为快排要是实现为递归的才方便呢，而且上来写了一个竟然是有问题的。
然后看网上别人写的，http://www.cnblogs.com/easonliu/p/4523941.html
感觉不仅是非递归写的非常漂亮，而且写的也非常标准。

感觉快排一定要好好的练练，这种题目考场应该是送分题，一定要好好把握。

*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
        int L = 0, R = nums.size()-1;
        while(L < R){
            int left = L, right = R;

            int mid = nums[left];
            while(left < right){
                while(left < right && nums[right] > mid)right--;
                nums[left] = nums[right];
                while(left < right && nums[left] <= mid)left++;
                nums[right] = nums[left];
            }
            nums[left] = mid;
            
            if(nums.size()-left-1 == k-1)return nums[left];
            else if(nums.size()-left-1 > k-1)L = left+1;
            else R = left-1;
        }
        return nums[nums.size()-k];
    }
};