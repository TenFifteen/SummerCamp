/*
题目大意：
一个数组织中，有一个元素的数量超过了n/2，找出该元素

解题思路：
两两对比

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int m, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt == 0) {
                m = nums[i];
                cnt = 1;
            }
            else if (nums[i] == m) cnt++;
            else cnt--;
        }
        
        return m;
    }
};
