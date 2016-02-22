/*
题目大意：
给定一个排序的数组，将其按照区间的方式输出出来。

解题思路：
直接进行遍历即可。

遇到的问题：
一开始忘了处理区间只有一个数的情况。
然后还忘了判断条件是nums[cur] == nums[cur-1]+1

再次阅读：
的确是个简单题。
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0)return ans;
        int last = 0;
        while(last < nums.size()){
            int cur = last+1;
            while(cur < nums.size() && nums[cur] == nums[cur-1]+1)cur++;
            if(last == cur-1)ans.push_back(to_string(nums[last]));
            else ans.push_back(to_string(nums[last]) + "->" + to_string(nums[cur-1]));
            last = cur;
        }
        return ans;
    }
};