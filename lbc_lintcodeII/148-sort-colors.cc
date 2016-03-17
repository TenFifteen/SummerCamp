/*
题目大意：
三路排序

解题思路：
三路排序。

遇到的问题：
没哟。
*/
class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return;
        
        int i = 0, j = 0, k = nums.size()-1;
        while (i <= k) {
            if (nums[i] < 1) {
                swap(nums[i++], nums[j++]);
            } else if (nums[i] > 1) {
                swap(nums[i], nums[k--]);
            } else {
                i++;
            }
        }
    }
};