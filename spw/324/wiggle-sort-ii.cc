/**
 * Problem: Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
 * Solve: find mid and three partition
 * Tips: see comments below.
 */
class Solution {
    private:
        int findMid(vector<int> &nums) {
            int k = nums.size() / 2;
            int left = 0, right = nums.size()-1;

            while (left < right) {
                int last = left;

                for (int i = left + 1; i <= right; ++i) {
                    if (nums[i] > nums[left]) {
                        swap(nums[i], nums[++last]);
                    }
                }
                swap(nums[last], nums[left]);

                if (last == k) return nums[last];
                else if (last < k) left = last + 1;
                else right = last - 1;
            }

            // if left < right, then return nums[left] at
            // last
            return nums[left];
        }
    public:
        void wiggleSort(vector<int>& nums) {
            int n = nums.size();
#define A(i) nums[(2*i+1)%(n|1)]

            int s = 0, m = 0, e = nums.size()-1;

            int target = findMid(nums);
            while (m <= e) {
                if (A(m) > target) {
                    swap(A(s++), A(m++));
                } else if (A(m) < target) {
                    swap(A(m), A(e--));
                } else {
                    m++;
                }
            }
        }
};
