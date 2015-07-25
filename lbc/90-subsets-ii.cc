/*
题目大意：
给定一个数字的集合，数字有重复。找出所有的组合的可能。

解题思路：
用深搜（回溯）的思想。对于递归树的某一层来讲，不可以使用同一个数字两次，也就
达到了去重的目的。

遇到的问题：
这道题目原来我好像是用的set来去重的。感觉不太好，就上网找了一下，找到了这个思路。
不过我还是不能用递归树的思路来想这个问题。还要多思考一下这个问题。
参考：http://www.cnblogs.com/x1957/p/3517989.html
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0)return ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        sub(ans, cur, nums, 0);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<int> &cur, vector<int> &nums, int index){
        ans.push_back(cur);
        for(int i = index; i < nums.size(); ++i){
            if(i != index && nums[i] == nums[i-1])continue;
            cur.push_back(nums[i]);
            sub(ans, cur, nums, i+1);
            cur.pop_back();
        }
    }
};