/**
 * Problem: Given two arrays, write a function to compute their intersection
 *          in which every element should be unique.
 * Solve: set
 * Tips: no
 */
class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            set<int> dict;
            vector<int> *arrPtr1 = &nums1, *arrPtr2 = &nums2;

            if (nums1.size() > nums2.size()) swap(arrPtr1, arrPtr2);

            for (int num : *arrPtr1) {
                dict.insert(num);
            }

            vector<int> ans;
            for (int num : *arrPtr2) {
                if (dict.find(num) != dict.end()) {
                    ans.push_back(num);
                    dict.erase(num);
                }
            }

            return ans;
        }
};
