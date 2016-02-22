/*
题目大意：
给一个数组，找出所有的子集合。

解题思路：
回溯。

遇到的问题：
竟然忘了排序。

再次阅读：
看了下之前的代码，没有任何问题。
但是感觉还是可以改成那种按照层次结构进行遍历的方式：
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> sub;  
        genSubsets(nums, 0, sub, subs);
        return subs; 
    }
    void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            genSubsets(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }
};
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        sub(ans, nums, 0, cur);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<int> &nums, int index, vector<int> &cur){
        if(index == nums.size()){
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[index]);
        sub(ans, nums, index+1, cur);
        cur.pop_back();
        sub(ans, nums, index+1, cur);
    }
};