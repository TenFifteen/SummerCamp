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
/*
第二次做：
比较简单。不过代码稍微冗余一点点。
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) return ans;

        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]+1) continue;

            if (nums[i-1] != last) ans.push_back(to_string(last) + "->" + to_string(nums[i-1]));
            else ans.push_back(to_string(last));
            last = nums[i];
        }

        if (nums.back() == last) ans.push_back(to_string(last));
        else (ans.push_back(to_string(last) + "->" + to_string(nums.back())));

        return ans;
    }
};
/*
 * ok
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) return ans;

        int index = 0;
        while (index < nums.size()) {
            int next = index+1;
            while (next < nums.size() && nums[next] == nums[next-1]+1) next++;
            if (next-1 != index) ans.push_back(to_string(nums[index]) + "->" + to_string(nums[next-1]));
            else ans.push_back(to_string(nums[index]));

            index = next;
        }
        return ans;
    }
};
