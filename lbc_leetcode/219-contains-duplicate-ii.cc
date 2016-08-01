/*
题目大意：
给定一个数组，问其中在一个窗口k大小内，是否存在重复的数字。

解题思路：
保持窗口大小不变，维护set

遇到的问题：
竟然min(k+1, nums.size())有语法错误。。。。。。

再次阅读：
用一个set是没有问题的。
不过可以使用unordered_set也许更好一些。
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        int len = nums.size();
        for(int i = 0; i < min(k+1, len); ++i){
            if(s.count(nums[i]))return true;
            s.insert(nums[i]);
        }
        for(int i = k+1; i < nums.size(); ++i){
            s.erase(nums[i-k-1]);
            if(s.count(nums[i]))return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
/*
第二次做：
没有太大问题。
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;

        unordered_set<int> s;
        int n = nums.size();
        for (int i = 0; i <= (k < n-1 ? k : n-1); ++i) {
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }

        for (int i = k+1; i < n; ++i) {
            s.erase(nums[i-k-1]);
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }

        return false;
    }
};
/*
 * graceful
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i) {
            if (um.find(nums[i]) == um.end() || i-um[nums[i]] > k) um[nums[i]] = i;
            else return true;
        }
        return false;
    }
};
