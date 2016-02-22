/*
题目大意：
给定一个排序的有重复的数组。允许重复的数字最多次数为2。求去重后的数组的长度，而且数组的
前len个数字正好是去重后的结果。

解题思路：
跟之前的26题是类似的，只不过这次的条件多了一个次数为2。

遇到的问题：
要不是回去看了26题的解法，自己还是想不出来啊。

再次阅读：
感觉之前的代码没啥太大问题了。但是竟然在DISCUSS中找到了一种更加简洁的写法：
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)return nums.size();
        int last = nums[0];
        int len = 1;
        int dup = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == last){
                if(dup == 1){
                    dup++;
                    swap(nums[i], nums[len]);
                    len++;
                }
            }else{
                last = nums[i];
                dup = 1;
                swap(nums[i], nums[len]);
                len++;
            }
        }
        return len;
    }
};