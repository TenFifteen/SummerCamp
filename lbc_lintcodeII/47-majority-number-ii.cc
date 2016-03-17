/*
题目大意：
一个数组中的主元素是超过了n/3的元素，找出该元素

解题思路：
跟超过二分之一的方式差不多，这次用两个计数器。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int m1, m2, cnt1 = 0, cnt2 = 0;
        for (auto n : nums) {
            if (m1 == n) cnt1++;
            else if (m2 == n) cnt2++;
            else if (cnt1 == 0) {
                m1 = n;
                cnt1++;
            } else if (cnt2 == 0) {
                m2 = n;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == m1) cnt1++;
            else if (nums[i] == m2) cnt2++;
        }
        
        if (cnt1 > nums.size()/3) return m1;
        if (cnt2 > nums.size()/3) return m2;
    }
};
