#include <stdio.h>
#include <stdlib.h>

/**
 * Problem: find the target in a rotated sorted array
 * Solve: find the pivot and convert the pos to the origin pos
 * Tips: how to find the samllest digit
 */
int search(int* nums, int numsSize, int target)
{
	int left = 0, right = numsSize - 1;
	// find the index of the smallest value using binary search.
	// Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
	// Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
	while (left < right) {
		int mid = (left + right) / 2;
		if (nums[mid] > nums[right]) {
			left = mid + 1;// the bigger one can pass
		} else {
			right = mid; // because we are looking for the samllest number, we just let the right=mid
		}
	}

	int r = left;
	printf("r = %d\n", r);
	left = 0, right = numsSize - 1;
	// we just try to find the realmid position
	while (left <= right) {
		int mid = (left + right) / 2;
		int realmid = (mid + r) % numsSize;
		if (nums[realmid] == target) {
			return realmid;
		} else if (nums[realmid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return -1;
}
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= nums[right]) right = mid;
            else left = mid + 1;
        }

        int pivot = left;
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int real = (mid + pivot) % nums.size();

            if (nums[real] == target) return real;
            else if (nums[real] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};

int main()
{
	int n, target;
	while (~scanf("%d %d", &n, &target)) {
		int *arr = malloc(sizeof(int) * (n + 1));
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		printf("The roated place is %d\n", search(arr, n, target));
	}

	return 0;
}
