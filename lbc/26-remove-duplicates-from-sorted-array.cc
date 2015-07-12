/*
题目大意：
给一个数组，排好序了。然后要去重，并且是原地去重，最后返回去重后的长度。

解题思路：
两个指针，第一个指向当前要处理的数字，第二个指向当前所有有效的数字的位置。

遇到的问题：
一开始没看清提议，只是返回了长度。然后看了提示，知道使用两个指针来做的，才想起来。
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int last = nums[0];
        int len = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == last)continue;
            last = nums[i];
            swap(nums[i],nums[len]);
            len++;
        }
        return len;
    }
};