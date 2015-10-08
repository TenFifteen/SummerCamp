/*
题目：33 % 颜色分类 中等

题目大意：
有三种颜色，将其按照0，1，2的顺序排列。

解题思路：
做了两遍二元分类

遇到的问题：
没有达到题目的一遍遍历的要求。
然后看了别人的解法，好像也并不是特别复杂，还是思路打不开啊。

精彩解答：
http://bubuko.com/infodetail-812680.html
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
        int left = 0, right = nums.size()-1;
        while (left < right) {
            while (left < right && nums[left] < 2) left++;
            while (left < right && nums[right] == 2) right--;
            swap(nums[left], nums[right]);
        }
        if (nums[left] < 2) {
            right = left;
        } else {
            right = left-1;
        }
        left = 0;
        while (left < right) {
            while (left < right && nums[left] == 0) left++;
            while (left < right && nums[right] == 1) right--;
            swap(nums[left], nums[right]);
        }
    }
};
