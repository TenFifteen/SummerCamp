/**
 * Problem: Given an array of integers, the majority number is the
 *          number that occurs more than half of the size of the array. Find it.
 * Solve: remove every different pair
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param nums: A list of integers
         * @return: The majority number
         */
        int majorityNumber(vector<int> nums) {
            int guard = 0, cnt = 0;

            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                if (nums[i] == guard) cnt++;
                else {
                    if (cnt == 0) {
                        ++cnt;
                        guard = nums[i];
                    } else {
                        --cnt;
                    }
                }
            }

            return guard;
        }
};

