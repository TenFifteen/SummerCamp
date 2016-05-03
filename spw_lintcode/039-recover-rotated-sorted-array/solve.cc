#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem: Given a rotated sorted array, recover it to sorted array in-place.
 * Solve: reverse, find the pivot, and reverse seperately.
 * Tips: see comments below.
 */
void recoverRotatedSortedArray(vector<int> &nums) {
    reverse(nums.begin(), nums.end());

    int left = 0, right = nums.size()-1;
    while (left < right) {
        // 1. consider when only two elements left to avoid infinite loop
        int mid = (left + right + 1) / 2;
        // 2. left or right to compare, determined by when the array hasn't been
        // rotated which half has to been abandon.
        if (nums[mid] < nums[left]) {
            left = mid;
        } else if (nums[mid] > nums[left]){
            right = mid - 1;
        } else {
            // 3. if there are duplicates just skip one each time.
            --left;
        }
    }

    reverse(nums.begin(), nums.begin()+left+1);
    reverse(nums.begin()+left, nums.end());
}

int main()
{
    int arr[] = {4, 5, 1, 2, 3};
    vector<int> nums(arr, arr+5);
    recoverRotatedSortedArray(nums);

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
