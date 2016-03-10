/*
题目大意：
给定一个数组，找出其中两个数的和是target，并将其下标按照从下到大的顺序输出来。

解题思路：
hash

遇到的问题：
没有。
*/
class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> ans;
        if (nums.size() < 2) return ans;
        
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(target-nums[i]) != hash.end()) {
                ans.push_back(hash[target-nums[i]]);
                ans.push_back(i+1);
                return ans;
            } else {
                hash[nums[i]] = i+1;
            }
        }
        
        return ans;
    }
};
