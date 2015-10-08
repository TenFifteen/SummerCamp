/*
题目：40 % 搜索旋转排序数组 II 中等

题目大意：
给定一个排序数组，右移一段，有重复，问target是否在数组中。

解题思路：
由于有重复，所以渐进复杂度是n，所以可以直接遍历了。

遇到的问题：
没有问题。
*/
class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        for (auto a : A) {
            if (a == target) return true;
        }
        return false;
    }
};
