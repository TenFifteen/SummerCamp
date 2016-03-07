/*
题目大意：
给定两个digit 数组，一个k值。从两个数组中挑出k个digit组成一个数，
使得在每个digit在源数组中保持顺序的情况下，找到一个最大的方案。

解题思路：
将问题分解为两个，首先是给定一个长度为m的数组，一个k-m的数组，合并两个数组，
使得结果最大。
第二个问题是，给定一个数组，取其中k个数字，组成的数字最大。
第一个问题的解可能会是n*n。第二个问题的解为n
所以总的复杂度为n*n 到n*n*n

遇到的问题：
不太会做，根本想不出来。看了别人的思路才知道怎么做的。
*/
class Solution {
    vector<int> maxk(const vector<int> &nums, int k) {
        vector<int> ans(k);
        int n = nums.size();
        
        for (int i = 0, j = 0; i < n; ++i) {
            while (n-i+j > k && j > 0 && ans[j-1] < nums[i]) j--;
            if (j < k) ans[j++] = nums[i];
        }
        
        return ans;
    }
    
    vector<int> merge(const vector<int> &nums1, const vector<int> &nums2) {
        int n1= nums1.size(), n2 = nums2.size();
        vector<int> ans(n1+n2);
        
        int i1 = 0, i2 = 0, i3 = 0;
        while (i1 < n1 && i2 < n2) {
            if (nums1[i1] < nums2[i2]) ans[i3++] = nums2[i2++];
            else if (nums1[i1] > nums2[i2]) ans[i3++] = nums1[i1++];
            else if (vgreater(vector<int>(nums1.begin()+i1+1, nums1.end()), vector<int>(nums2.begin()+i2+1, nums2.end()))) {
                ans[i3++] = nums1[i1++];
            } else {
                ans[i3++] = nums2[i2++];
            }
        }
        
        while (i1 < n1) ans[i3++] = nums1[i1++];
        while (i2 < n2) ans[i3++] = nums2[i2++];
        
        return ans;
    }
    
    bool vgreater(const vector<int> &nums1, const vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        int i1 = 0, i2 = 0;
        while (i1 < n1 && i2 < n2 && nums1[i1] == nums2[i2]) {
            i1++; i2++;
        } 
        
        if (i2 == n2) {
            return i1 != n1;
        } else {
            if (i1 == n1) return false;
            return nums1[i1] > nums2[i2];
        }
    }
    
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k, 0);
        int n1 = nums1.size(), n2 = nums2.size();
        
        for (int i = max(0, k-n2); i <= k && i <= n1; ++i) {
            auto now = merge(maxk(nums1, i), maxk(nums2, k-i));
            if (vgreater(now, ans)) ans = now;
        }
        
        return ans;
    }
};