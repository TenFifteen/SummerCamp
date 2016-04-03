/*
题目大意：
给定一个数组，找到一种一个子数组，其和等于0

解题思路：
见代码。

遇到的问题：
没有。
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
        vector<int> ans(2, -1);
        
        unordered_map<int, int> hash;
        hash[0] = -1;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (hash.find(sum) != hash.end()) {
                ans[0] = hash[sum]+1;
                ans[1] = i;
                return ans;
            }
            
            hash[sum] = i;
        }
        return ans;
    }
};