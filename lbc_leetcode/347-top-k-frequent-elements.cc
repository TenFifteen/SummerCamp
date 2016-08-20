/*
 * nlogk. but there is a better one in discuss. bucket sort, just O(n).
 * https://discuss.leetcode.com/topic/44237/java-o-n-solution-bucket-sort
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (auto n : nums) um[n]++;

        set<pair<int, int>> s;
        for (auto u : um) {
            s.insert(make_pair(u.second, u.first));
            if (s.size() > k) s.erase(*s.begin());
        }

        vector<int> ans;
        for (auto p : s) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
