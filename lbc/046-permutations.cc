/*
题目大意：
给一个数组，求出所有的排列。

解题思路：
回溯。

遇到的问题：
一次通过。

再次阅读：
感觉我之前的做法没有啥问题，就是这么一个递归的过程。
但是看了一下DISCUSS之后发现，人家还有更简洁的方式来表达这个过程：
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;

        permuteRecursive(num, 0, result);
        return result;
    }

    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin >= num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }

        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            // reset
            swap(num[begin], num[i]);
        }
    }
};
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flag(nums.size(), false);
        vector<int> cur;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        sub(ans, nums, cur, flag);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<int> &nums, vector<int> &cur, vector<bool> &flag){
        if(cur.size() == nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(flag[i])continue;
            if(i != 0 && nums[i] == nums[i-1])continue;
            cur.push_back(nums[i]);
            flag[i] = true;
            sub(ans, nums, cur, flag);
            cur.pop_back();
            flag[i] = false;
        }
    }
};