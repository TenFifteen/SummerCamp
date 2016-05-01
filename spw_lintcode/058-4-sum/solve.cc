/**
 * Problem: Given an array S of n integers, are there elements a, b, c, and
 *          d in S such that a + b + c + d = target?
 * Solve: sort + two pointers
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param numbers: Give an array numbersbers of n integer
         * @param target: you need to find four elements that's sum of target
         * @return: Find all unique quadruplets in the array which gives the sum of
         *          zero.
         */
        vector<vector<int> > fourSum(vector<int> nums, int target) {
            sort(nums.begin(), nums.end());

            vector<vector<int> > ans;
            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    int tmp = nums[i] + nums[j];
                    int left = j + 1, right = n - 1;

                    while (left < right) {
                        int sum = tmp + nums[left] + nums[right];
                        if (sum == target) {
                            vector<int> one(4, 0);
                            one[0] = nums[i]; one[1] = nums[j];
                            one[2] = nums[left]; one[3] = nums[right];
                            ans.push_back(one);

                            while (left < right && nums[left] == one[2]) ++left;
                            while (left < right && nums[right] == one[3]) --right;
                        } else if (sum < target) {
                            ++left;
                        } else {
                            right--;
                        }
                    }

                    while (j+1 < n && nums[j+1] == nums[j]) ++j;
                }

                while (i+1 < n && nums[i+1] == nums[i]) ++i;
            }

            return ans;
        }
};

