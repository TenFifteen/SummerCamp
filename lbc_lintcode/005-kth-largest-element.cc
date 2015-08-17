/*
题目：第k大元素 中等

题目大意：
找到第k大的数

解题思路：
用快排的思想，可以在平均复杂度为n的情况下找到

遇到的问题：
一开始在内部循环中，忘记了限制left < right了。
这道题也是属于极其经典的饿题目了，必须要熟练掌握快排的过程。
*/
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int L = 0, R = nums.size()-1;
        while (L < R) {
            int left = L, right = R;
            int mid = nums[left];
            while (left < right) {
                while (left < right && nums[right] < mid)right--;
                nums[left] = nums[right];
                while (left < right && nums[left] >= mid)left++;
                nums[right] = nums[left];
            }
            nums[left] = mid;
            if (left == k-1)return nums[left];
            if (left < k-1) L = left+1;
            else R = left-1;
        }
        return nums[k-1];
    }
};
