#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

/**
 * Problem: Given an integer array, find subarray with sum closest to zero.
 *          Return the indexes of the first number and the last number.
 * Solve: sort the accumulate sums.
 * Tips: 1. sum[i, j] = acc[j] - acc[i-1], then we should put aside element:acc[-1] = 0;
 *       2. we should use pair to remember the position for sort.
 */
class Solution {
    public:
        /**
         * @param nums: A list of integers
         * @return: A list of integers includes the index of the first number
         *          and the index of the last number
         */
        vector<int> subarraySumClosest(vector<int> nums){
            // write your code here
            int n = nums.size();
            if (n == 0) {
                vector<int> tmp;
                return tmp;
            }

            vector<pair<int, int> > acc(n+1);
            acc[0] = make_pair(0, -1);

            for (int i = 0; i < n; ++i) {
                acc[i+1] = make_pair(acc[i].first + nums[i], i);
            }

            sort(acc.begin(), acc.end());

            int min_diff = INT_MAX;
            vector<int> ans(2);
            for (int i = 1; i < n+1; ++i) {
                int diff = abs(acc[i].first - acc[i-1].first);
                if (diff < min_diff) {
                    min_diff = diff;
                    if (acc[i].second < acc[i-1].second) {
                        ans[0] = acc[i].second + 1;
                        ans[1] = acc[i-1].second;
                    } else {
                        ans[0] = acc[i-1].second + 1;
                        ans[1] = acc[i].second;
                    }
                    if (min_diff == 0) return ans;
                }
            }

            return ans;
        }
};


int main()
{

}
