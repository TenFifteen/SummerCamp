/**
 * Problem: Given an integer array of size n, find all elements that
 *          appear more than n/3 times. The algorithm should run in
 *          linear time and in O(1) space.
 * Solve: Eliminate every three different element one time.
 * Tips: judge equation before judge zero of count.
 *       or a will equal to b
 */
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int cnt1 = 0, cnt2 = 0;
            int a = 0, b = 0;

            for (int num : nums) {
                if (num == a) {
                    cnt1++;
                    a = num;

                } else if (num == b) {
                    cnt2++;
                    b = num;

                } else if (cnt1 == 0){
                    a = num;
                    cnt1 = 1;

                } else if (cnt2 == 0){
                    b = num;
                    cnt2 = 1;

                } else {
                    cnt1--;
                    cnt2--;

                }

            }

            cnt1 = cnt2 = 0;
            for (int num : nums) {
                if (num == a) cnt1++;
                else if (num == b) cnt2++;

            }

            vector<int> ans;
            if (cnt1 > nums.size()/3) ans.push_back(a);
            if (cnt2 > nums.size()/3) ans.push_back(b);

            return ans;

        }

};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if (nums.size() == 0) return ans;

        int n = nums.size();
        int guard1, guard2, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            // compare the elements not zero first
            if (cnt1 == 0 && (cnt2 == 0 || guard2 != nums[i]) || guard1 == nums[i]) {
                guard1 = nums[i];
                cnt1++;
            } else if (cnt2 == 0 || guard2 == nums[i]) {
                guard2 = nums[i];
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (num == guard1) cnt1++;
            else if (num == guard2) cnt2++;
        }

        if (cnt1 > n/3) ans.push_back(guard1);
        if (cnt2 > n/3) ans.push_back(guard2);

        return ans;
    }
};
