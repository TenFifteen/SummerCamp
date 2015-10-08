/*
题目：27 % 两数之和 中等

题目大意：
给定一个数组，问其中哪两个数的和等于target。
答案只有一组

解题思路：
先将每个数跟原来的下标联系起来，然后排序，两指针做

遇到的问题：
一开始没有考虑下标；然后没有考虑返回值有序。
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
        vector<pair<int,int>> data(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            data[i].first = nums[i];
            data[i].second = i + 1;
        }
        sort(data.begin(), data.end());
        int left = 0, right = nums.size()-1;
        vector<int> ans(2);
        while (left < right) {
            int cur = data[left].first + data[right].first;
            if (cur == target) {
                ans[0] = data[left].second;
                ans[1] = data[right].second;
                sort(ans.begin(), ans.end());
                return ans;
            } else if (cur < target) {
                left++;
            } else {
                right--;
            }
        }
    }
};

