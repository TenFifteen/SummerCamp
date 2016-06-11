/**
 * Problem: Given two arrays, write a function to compute their intersection.
 * Solve: sort and compare
 * Tips: no
 */
class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());

            int i = 0, j = 0, len1 = nums1.size(), len2 = nums2.size();

            vector<int> ans;
            while (i < len1 && j < len2) {
                if (nums1[i] < nums2[j]) {
                    ++i;
                } else if (nums1[i] > nums2[j]) {
                    ++j;
                } else {
                    ans.push_back(nums1[i]);
                    ++i, ++j;
                }
            }

            return ans;
        }
};
