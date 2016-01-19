#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: find kth largest element in an array.
 * Solve: use quick sort.
 * Tips: 1. kth largest.
 *       2. use a variable and a flag
 */
class Solution {
    private:
        bool find = false;
        int ans = 0;
    public:
        void swap(vector<int> &nums, int i, int j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }

        void mysort(vector<int> &nums, int left, int right, int k) {
            if (find) return;

            if (left >= right) return;

            swap(nums, left, (left+right)/2);
            int last = left;
            for (int i = left+1; i <= right; ++i) {
                if (nums[i] > nums[left]) {
                    swap(nums, i, ++last);
                }
            }
            swap(nums, left, last);

            if (last == k - 1) {
                find = true;
                ans = nums[last];
                return;
            }
            mysort(nums, left, last-1, k);
            mysort(nums, last+1, right, k);
        }
        /*
         * param k : description of k
         * param nums : description of array and index 0 ~ n-1
         * return: description of return
         */
        int kthLargestElement(int k, vector<int> nums) {
            // write your code here
            ans = 0;
            find = false;
            mysort(nums, 0, nums.size()-1, k);

            if (find) return ans;
            else return nums[k-1];
        }
};
