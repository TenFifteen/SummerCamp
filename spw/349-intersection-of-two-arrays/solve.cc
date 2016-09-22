/**
 * Problem: Given two arrays, write a function to compute their intersection.
 *          Each element in the result must be unique.
 *          The result can be in any order.
 * Solve: hash set
 * Tips: no
 */
class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            vector<int> *p1 = &nums1, *p2 = &nums2;
            if (p1->size() > p2->size()) swap(p1, p2);

            unordered_set<int> table;
            for (int num : *p1) table.insert(num);

            vector<int> ans;
            for (int num : *p2) {
                if (table.find(num) != table.end()) {
                    ans.push_back(num);
                    table.erase(num);
                }
            }

            return ans;
        }
};
