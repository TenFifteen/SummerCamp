/*
题目大意：
给定一个数组，找到其中三个数，使得其sum与target最接近。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        
        int ans = nums[0]+nums[1]+nums[2];
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            
            int left = i+1, right = nums.size()-1;
            while (left < right) {
                int cur = nums[i] + nums[left] + nums[right];
                if (abs(target-cur) < abs(target-ans)) ans = cur;
                
                if (cur < target) left++;
                else if (cur > target) right--;
                else return target;
            }
        }
        
        return ans;
    }
};
