/*
题目大意：
给一个数组，一个val。删除所有值为val的元素，返回长度。也是原地删除。

解题思路：
与26题一样。两个指针。

遇到的问题：
并没有问题。
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)return 0;
        int len = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != val){
                if(i != len){
                    swap(nums[len], nums[i]);
                }
                len++;
            }
        }
        return len;
    }
};