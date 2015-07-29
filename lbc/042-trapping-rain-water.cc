/*
题目大意：
给一个非负的数组，假设每个宽度是1.从上面下雨，问该数组最大的盛水量。

解题思路：
找出每一个数字的左右边界的最小值。如果该边界比自己大，就可以计算自己可以盛多少水。

遇到的问题：
无问题。
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)return 0;
        vector<int> water(height.size(), -1);
        int bar = height[0];
        for(int i = 1; i < height.size(); ++i){
            water[i] = max(bar, height[i]);
            bar = max(bar, height[i]);
        }
        bar = height[height.size()-1];
        for(int i = height.size()-2; i >= 0; --i){
            water[i] = min(water[i], bar);
            bar = max(bar, height[i]);
        }
        int ans = 0;
        for(int i = 1; i < height.size()-1; ++i){
            if(water[i]-height[i] > 0)ans += water[i]-height[i];
        }
        return ans;
    }
};