/**
 * Problem: Given a unsorted array with integers, find the median of it.
 *          A median is the middle number of the array after it is sorted.
 *          If there are even numbers in the array, return the N/2-th number after sorted.
 * Solve: partion
 * Tips: care about the detail
 */
#include <iostream>
#include <vector>

using namespace std;

int median(vector<int> &nums) {
    int n = nums.size(), mid = (n-1)/2;

    int left = 0, right = n-1;
    while (left <= right) {
        int last = left;
        for (int i = left+1; i <= right; ++i)
            if (nums[i] < nums[left])
                swap(nums[++last], nums[i]);
        swap(nums[left], nums[last]);

        if (last == mid) return nums[last];
        else if (last < mid) left = last + 1;
        else right = last - 1;
    }
}

int main()
{
    int arr[] = {4,5,1,2,3};
    vector<int> in(arr, arr+5);
    cout << median(in) << endl;

    return 0;
}
