/**
 * Problem: Given an array nums, there is a sliding window of size k  which is
 *          moving from the very left of the array to the very right. You can
 *          only see k numbers in the window. Each time the sliding window moves
 *          right by one position.
 * Solve: Sustain a sequence of monotone increasing order using a dequeue.
 * Tips: Save index instead of numbers in the dequeue.
 *       Push index to the back of the dequeue every time.
 */
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> incSeq;
            vector<int> ans;

            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                if (!incSeq.empty() && incSeq.front() == i-k) incSeq.pop_front();
                while (!incSeq.empty() && nums[incSeq.back()] <= nums[i]) {
                    incSeq.pop_back();
                }

                incSeq.push_back(i);
                if (i >= k-1) {
                    ans.push_back(nums[incSeq.front()]);
                }
            }
            return ans;
        }

};
