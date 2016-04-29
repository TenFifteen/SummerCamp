#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Given a sorted array of n integers, find the starting
 *          and ending position of a given target value.
 *          If the target is not found in the array, return [-1, -1]
 * Solve: binary search with condition that left < right.
 * Tips: see comments below.
 */
vector<int> searchRange(vector<int> &A, int target) {
    vector<int> ans(2, -1);

    int left = 0, right = A.size()-1;
    while (left < right) {
        int mid = (left + right) / 2;
        // mid round to zero, then we don't need to
        // worry about the infinite loop, when right = left+1
        // the next judgement comes in a similar way.
        if (A[mid] >= target) right = mid;
        else left = mid + 1;

    }
    if (A[right] == target) ans[0] = left;


    left = 0, right = A.size()-1;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (A[mid] > target) right = mid-1;
        else left = mid;
    }
    if (A[left] == target) ans[1] = left;

    return ans;
}

int main()
{
    int arr[] = {5, 7, 7, 8, 8, 10};
    vector<int> A(arr, arr+6);
    searchRange(A, 8);
}
