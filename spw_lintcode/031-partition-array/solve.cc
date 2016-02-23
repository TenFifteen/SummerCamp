#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Given an array nums of integers and an int k,
 *          partition the array
 * Solve: qsort.
 * Tips: no
 */
class Solution {
public:
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    int partitionArray(vector<int> &nums, int k) {
        int last = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < k) {
                swap(nums, i, last++);
            }
        }
        return last;
    }
};
