/*
题目：25 % 子数组之和 容易

题目大意：
给定一个没有顺序的数组，问其中一个子数组的和为0，问其起止位置。

解题思路：
直接二维遍历

遇到的问题：
总觉得这道题目没有这么简单，这种方法也太naive了。但是竟然过了。

果然是自己想不到呀。网上还是有人做的非常好看的。是n的复杂度。
http://www.cnblogs.com/easonliu/p/4543647.html
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        vector<int> ret(2);
        if (nums.size() == 0) {
            return ret;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int sum = nums[i];
            if (sum == 0) {
                ret[0] = i;
                ret[1] = i;
                return ret;
            }
            for (int j = i+1; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == 0) {
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
                }
            }
        }
        return ret;
    }
};
