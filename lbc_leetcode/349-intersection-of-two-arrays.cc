/*
 * ok
 * /
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> us;
        for (auto n : nums1) {
            us.insert(n);
        }
        for (auto n : nums2) {
            if (us.find(n) != us.end()) {
                ans.push_back(n);
                us.erase(n);
            }
        }
        return ans;
    }
};
