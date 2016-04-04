/**
 * Problem: Given an array of n integer with duplicate number, and a moving
 *          window(size k), move the window at each iteration from the start
 *          of the array, find the maximum number inside the window at each moving.
 * Solve: use a double queue to keep a increase sequence with length less than k
 * Tips: no
 */
class Solution {
    public:
        /**
         ** @param nums: A list of integers.
         ** @return: The maximum number inside the window at each moving.
         **/
        vector<int> maxSlidingWindow(vector<int> &nums, int k) {
            deque<int> buffer;

            int n = nums.size();

            vector<int> ans;
            for (int i = 0; i < n; ++i) {
                while (!buffer.empty() && nums[buffer.back()] <= nums[i])
                    buffer.pop_back();
                buffer.push_back(i);

                if (buffer.front() < i-k+1) buffer.pop_front();

                if (i >= k-1) ans.push_back(nums[buffer.front()]);
            }

            return ans;
        }

};
