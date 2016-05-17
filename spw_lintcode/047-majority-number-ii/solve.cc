/**
 * Problem: Given an array of integers, the majority number is the
 *          number that occurs more than 1/3 of the size of the array.
 * Solve: elimit there different numbers.
 * Tips: must count the left two guards.
 */
class Solution {
    public:
        /**
         * @param nums: A list of integers
         * @return: The majority number occurs more than 1/3.
         */
        int majorityNumber(vector<int> nums) {
            int ga, gb, cnt1 = 0, cnt2 = 0;

            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                if (cnt1 == 0 || nums[i] == ga) {
                    ga = nums[i];
                    cnt1++;
                } else if (cnt2 == 0 || nums[i] == gb) {
                    gb = nums[i];
                    cnt2++;
                } else {
                    cnt1--;
                    cnt2--;
                }
            }

            cnt1 = cnt2 = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == ga) ++cnt1;
                else if (nums[i] == gb) ++cnt2;
            }

            if (cnt1 > n/3) return ga;
            else return gb;
        }
};

