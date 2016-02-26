/**
 * Problem: Find the kth largest element in an array. Note that it is
 *          the kth largest element in the sorted array.
 * Solve: heap sort.
 * Tips: mind the details.
 */
class Solution {
    private:
        void swap(vector<int> &nums, int i, int j) {
            if (nums[i] == nums[j]) return;
            nums[i] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
            nums[i] = nums[i] ^ nums[j];
        }

        void maxHeapify(vector<int> &nums, int root, int n) {
            int child = root * 2 + 1;
            if (child >= n) return;

            // max heapify
            if (child+1 < n && nums[child+1] > nums[child]) ++child;

            // note the condition
            if (nums[child] > nums[root]) {
                swap(nums, root, child);
                maxHeapify(nums, child, n);
            }
        }
    public:
        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
            for (int i = (n-2)/2; i >= 0; --i) {
                maxHeapify(nums, i, n);
            }

            // swap 0
            for (int i = 0; i < k-1; ++i) {
                swap(nums, 0, n-1);
                n--;
                maxHeapify(nums, 0, n);
            }

            return nums[0];
        }
};
