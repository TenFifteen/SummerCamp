/**
 * Problem: Given two arrays, write a function to compute their intersection.
 * The result can be in any order.
 * Solve: hash map
 * Tips: no
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *p1 = &nums1, *p2 = &nums2;
        if (p1->size() > p2->size()) swap(p1, p2);

        unordered_map<int, int> table;
        for (int num : *p1) table[num]++;

        vector<int> ans;
        for (int num : *p2) {
            if (table.find(num) != table.end()) {
                ans.push_back(num);
                if (--table[num] == 0)
                    table.erase(num);
            }
        }

        return ans;
    }
};
