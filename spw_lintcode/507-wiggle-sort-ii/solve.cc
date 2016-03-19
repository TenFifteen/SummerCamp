/**
 * Problem: Given an unsorted array nums, reorder it such that
 *           nums[0] < nums[1] > nums[2] < nums[3]....
 * Solve: find the middle number and use the three partition.
 * Tips: see comments below.
 */
class Solution {
    public:
        int findMid(vector<int> &nums) {
            int left = 0, right = nums.size() - 1;
            int k = nums.size() >> 1;

            while (left <= right) {
                int l = left, r = right;
                // must select the left, if you want to
                // select in the middle postition, you must
                // swap it to the left position.
                // because first we use nums[l] to override
                // it, then at last we use nums[l] = mid to
                // place it right.
                int mid = nums[l];
                while (l < r) {
                    while (l < r && nums[r] > mid) --r;
                    nums[l] = nums[r];
                    while (l < r && nums[l] <= mid) ++l;
                    nums[r] = nums[l];
                }
                nums[l] = mid;

                if (l == k) return mid;
                else if (l < k) {
                    left = l + 1;
                } else {
                    right = l - 1;
                }
            }
        }
        /**
         * @param nums a list of integer
         * @return void
         */
        void wiggleSort(vector<int>& nums) {
            // Write your code here
            int mid = findMid(nums);
            int n = nums.size();

#define A(i) nums[(2*i+1) % (n|1)]

            // the three partition will keep all the middle elements
            // in the middle position.
            int l = 0, m = 0, r = n -1;
            while (m <= r) {
                if (A(m) > mid) {
                    // the l will push m to get forward.
                    swap(A(m++), A(l++));
                } else if (A(m) < mid) {
                    swap(A(m), A(r--));
                } else {
                    ++m;
                }
            }
        }
};
