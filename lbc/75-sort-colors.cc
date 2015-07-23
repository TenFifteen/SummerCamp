/*
题目大意：
给定一个数组，数组中只有0，1，2三种数字。然后排序。

解题思路：
本来想着是计数排序不是挺好的么。一看题目，竟然有提示说可以有更优的方法。
然后就是弄两个指针分别指向当前0的边界和2的边界，一遍遍历就可以解决了。

遇到的问题：
本来这个一遍遍历的想法是没想出来的，只想出了计数排序。看了网上的解法才知道的。
看来还是功底不够啊。
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, right = nums.size();
        for(int i = 0; i < right; ++i){
            if(nums[i] == 0){
                swap(nums[i], nums[++left]);
            }else if(nums[i] == 2){
                swap(nums[i], nums[--right]);
                --i;
            }
        }
    }
};