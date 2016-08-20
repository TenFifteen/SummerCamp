/*
 * find new land again.
 * firstly, how to use closure in C++, [](){};
 * secondly, decltype, and set initialize method.
 * thirdly, the algorithm. look at :https://discuss.leetcode.com/topic/50481/clean-16ms-c-o-n-space-o-klogn-time-solution-using-priority-queue
 */
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ans;
        if (nums1.size() == 0 || nums2.size() == 0 || k <= 0) return ans;

        auto cmp = [nums1, nums2](const pair<int, int> &p1, const pair<int, int>p2) {
            return nums1[p1.first]+nums2[p1.second] < nums1[p2.first]+nums2[p2.second];
        };
        multiset<pair<int, int>, decltype(cmp)> ms(cmp);
        ms.insert(make_pair(0, 0));

        for (int i = 0; i < k && ms.size() > 0; ++i) {
            auto cur = *ms.begin(); ms.erase(ms.begin());
            ans.push_back(make_pair(nums1[cur.first], nums2[cur.second]));
            if (cur.first+1 < nums1.size()) ms.insert(make_pair(cur.first+1, cur.second));
            if (cur.first == 0 && cur.second+1 < nums2.size()) ms.insert(make_pair(0, cur.second+1));
        }
        return ans;
    }
};
