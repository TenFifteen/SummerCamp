/*
 * ok
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> um;
        for (auto n : nums1) {
            um[n]++;
        }
        for (auto n : nums2) {
            um[n]--;
            if (um[n] >= 0) ans.push_back(n);
        }
        return ans;
    }
};
