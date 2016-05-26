/*
题目大意：
给定一个数组，求出除了每一个数字之外，其他所有数字的乘积。不可以用除法。

解题思路：
先求出从0到k元素的乘积，已经k到n的乘积。然后就可以求出除了k元素的乘积。

遇到的问题：
一次通过。

不过题目中说是否可以除了ret之外，不额外开辟空间。
其实是可以的。将right直接存在ret中。然后计算left的时候，边计算边更新ret。不需要额外的存储left。
就变成了常数空间复杂度了。

再次阅读：
没有太大问题，就是想了想不知道怎么将空间复杂度降到O(1)，然后看到DISCUSS中有一个很巧妙的方法：
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int fromBegin=1;
        int fromLast=1;
        vector<int> res(n,1);

        for(int i=0;i<n;i++){
            res[i]*=fromBegin;
            fromBegin*=nums[i];
            res[n-1-i]*=fromLast;
            fromLast*=nums[n-1-i];
        }
        return res;
    }
};
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size()), right(nums.size());
        left[0] = nums[0];
        right[nums.size()-1] = nums[nums.size()-1];
        for(int i = 1; i < nums.size(); ++i){
            left[i] = left[i-1] * nums[i];
            right[nums.size()-1-i] = right[nums.size()-i] * nums[nums.size()-1-i];
        }
        vector<int> ret(nums.size());
        ret[0] = right[1];
        ret[nums.size()-1] = left[nums.size()-2];
        for(int i = 1; i < nums.size()-1; ++i){
            ret[i] = left[i-1] * right[i+1];
        }
        return ret;
    }
};
/*
第二次做：
这次还好，自己找到了空间O(1)的算法了。
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        
        int right = 1;
        for (int i = nums.size()-2; i >= 0; --i) {
            right *= nums[i+1];
            ans[i] *= right;
        }
        
        return ans;
    }
};