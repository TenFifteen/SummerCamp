/*
题目大意：
给定一个数组，求出其中所有的数量超过n/3的数字。

解题思路：
二分查找。

遇到的问题：
一开始忘记了两遍结果的去重。
并且将只有两个元素的情况搞错了。
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        return sub(nums, 0, nums.size()-1);
    }
    
    vector<int> sub(vector<int> &nums, int left, int right){
        vector<int> ans;
        if(right < left)return ans;
        if(left == right){
            ans.push_back(nums[left]);
            return ans;
        }
        if(left+1 == right){
            ans.push_back(nums[left]);
            if(nums[right] != nums[left])ans.push_back(nums[right]);
            return ans;
        }
        int mid = left + (right-left+1)/2;
        auto ret_l = sub(nums, left, mid);
        auto ret_r = sub(nums, mid+1, right);
        
        set<int> visited;
        
        for(auto r:ret_l){
            if(visited.count(r))continue;
            int cnt = 0;
            for(int i = left; i <= right; ++i){
                if(nums[i] == r)cnt++;
            }
            if(cnt > (right-left+1)/3){
                ans.push_back(r);
                visited.insert(r);
            }
        }
        for(auto r:ret_r){
            if(visited.count(r))continue;
            int cnt = 0;
            for(int i = left; i <= right; ++i){
                if(nums[i] == r)cnt++;
            }
            if(cnt > (right-left+1)/3){
                ans.push_back(r);
                visited.insert(r);
            }
        }
        return ans;
    }
};