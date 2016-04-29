#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Given an array S of n integers, are there elements a, b, c in S
 *          such that a + b + c = 0? Find all unique triplets in the array
 *          which gives the sum of zero.
 * Solve: sort + two pointers.
 * Tips: duplicates numbers.
 */
vector<vector<int> > threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int> > ans;

    int n = nums.size();
    if (n < 3) return ans;
    for (int i = 0; i < n; ++i) {
        int left = i+1, right = n-1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                vector<int> tmp(3, 0);
                tmp[0] = nums[i]; tmp[1] = nums[left]; tmp[2] = nums[right];
                ans.push_back(tmp);

                // pass by now number, then we test now instead of the advanced
                // case
                while (left < right && nums[left] == tmp[1]) ++left;
                while (right > left && nums[right] == tmp[2]) --right;
            }else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }

        // because there is ++i in the main loop, we need test advanced
        while (i+1 < n && nums[i+1] == nums[i]) ++i;
    }

    return ans;
}

int main()
{
    int arr[] = {-1, 1, 0};
    vector<int> nums(arr, arr+3);
    threeSum(nums);

    return 0;
}
