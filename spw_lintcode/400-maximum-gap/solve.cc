#include <iostream>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

/**
 * Problem: Given an unsorted array, find the maximum difference between
 *          the successive elements in its sorted form.
 *          return 0 if the array contains less than 2 elements.
 * Solve: bucket sort.
 * Tips: 1. Bucket size.
 *       2. 0 2147483647
 *       3. Skip empty bucket.
 */
class Solution {
    public:
        /**
         * @param nums: a vector of integers
         * @return: the maximum difference
         */
        int maximumGap(vector<int> nums) {
            int n = nums.size();
            if (n < 2) return 0;

            int max_num = nums[0], min_num = nums[0];
            for (int i = 0; i < n; ++i) {
                if (nums[i] > max_num) max_num = nums[i];
                if (nums[i] < min_num) min_num = nums[i];
            }

            int num_range = max_num - min_num + 1;
            // handle the range
            if (num_range == INT_MIN) num_range = INT_MAX;
            // when handle the range, we can raise an example.
            // for example: 0 1 3 7.
            int bucket_size = ceil((double)num_range / n);

            vector<int> bucket_max(n, INT_MIN);
            vector<int> bucket_min(n, INT_MAX);

            for (int i = 0; i < n; ++i) {
                int id = (nums[i] - min_num) / bucket_size;
                bucket_max[id] = max(bucket_max[id], nums[i]);
                bucket_min[id] = min(bucket_min[id], nums[i]);
            }

            int last_max = bucket_max[0];
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                // bucket is empty
                if (bucket_max[i] < bucket_min[i]) continue;
                ans = max(ans, bucket_min[i] - last_max);
                last_max = bucket_max[i];
            }

            return ans;
        }
};

int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(2147483647);

    Solution *s = new Solution();
    cout << s->maximumGap(nums) << endl;

    return 0;
}
