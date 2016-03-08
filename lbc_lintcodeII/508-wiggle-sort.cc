/*
题目大意：
给定一个无序数组，将其排列成A[0] <= A[1] >= A[2] <= A[3] >= A[4]...这种造型。
最好是不用额外的空间，时间是n

解题思路：
先找到数组的中位数，然后把数组的下标映射一下。映射为1,3,5,7,9....,2,4,6,8,...
然后运行三路排序算法。

遇到的问题：
看着那个下标的映射感觉两种映射都应该是可以的，可是实际上呢，如果映射到0,2,4,6,8,...1,3,5,7,9..
不太好操作。
另外就是那个二分，最后更新left和right的时候用的是mid，而不是L。让我一顿好找啊。
*/
class Solution {
    int getMiddle(vector<int> &nums) {
        int left = 0, right = nums.size()-1, k = nums.size()/2;
        
        while (left <= right) {
            int mid = nums[left];
            int L = left, R = right;
            while (L < R) {
                while (L < R && nums[R] > mid) R--;
                nums[L] = nums[R];
                while (L < R && nums[L] <= mid) L++;
                nums[R] = nums[L];
            }
            nums[L] = mid;

            if (L == k) return nums[L];
            else if (L > k) right = L-1;
            else left = L+1;
        }
    }

    int A(int i, int n) {
        return (i*2+1) % (n|0x1);
    } 

public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        if (nums.size() == 0) return;
        
        int mid = getMiddle(nums);
        int n = nums.size();
        
        int i = 0, j = 0, k = n-1;
        while (i <= k) {
            if (nums[A(i,n)] > mid) {
                swap(nums[A(i++,n)], nums[A(j++,n)]);
            } else if (nums[A(i,n)] < mid) {
                swap(nums[A(k--,n)], nums[(A(i,n))]);
            } else {
                i++;
            }
        }
    }
};