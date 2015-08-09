/*
题目大意：
给定一个数组，问在一个窗口k内，是否存在元素的差小于t

解题思路：
维护窗口k的set。
然后查找是否存在在范围k内的元素。

遇到的问题：
思路是有的。只是一开始没有找到set可以直接进行二分查找的方法，然后自己手工模拟了一个，效率稍低，
超时了。
结果看了别人的方法，才知道有lower_bound这么一个神奇的方法。
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> buf;
        for(int i = 0; i < nums.size(); ++i){
            if(buf.size() == k+1)buf.erase(nums[i-k-1]);
            auto it = buf.lower_bound(nums[i]-t);
            if(it != buf.end() && abs(*it - nums[i]) <= t)return true;
            buf.insert(nums[i]);
        }
        return false;
    }
};