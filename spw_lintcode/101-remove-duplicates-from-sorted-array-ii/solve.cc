/**
 * Problem: Follow up for "Remove Duplicates":
 *          What if duplicates are allowed at most twice?
 * Solve: count
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param A: a list of integers
         * @return : return an integer
         */
        int removeDuplicates(vector<int> &nums) {
            int n = nums.size();
            if (n == 0) return 0;

            int num = nums[0], cnt = 1;
            int index = 1;

            bool skipped = false;
            for (int i = 1; i < n; ++i) {
                if (nums[i] == num) {
                    cnt++;
                    if (cnt > 2) skipped = true;
                } else {
                    skipped = false;
                    num = nums[i];
                    cnt = 1;
                }

                if (!skipped) nums[index++] = nums[i];
            }

            return index;
        }
};
