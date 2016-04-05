#include <stdio.h>
#include <stdlib.h>

#define N 100

void swap(int v[], int a, int b)
{
	if (v[a] == v[b]) return;
	v[a] = v[a] ^ v[b];
	v[b] = v[a] ^ v[b];
	v[a] = v[a] ^ v[b];
}
/**
 * Problem: I think the decription is puzzling. It should be: given an array of N,
 *          find the missing integer in the sequences 1...N, because the given array
 *          may contains duplicates or the number out of range.
 * Solve: place each number in its place. For example, put 3 to a[2], put 1 to a[0].
 * Tips: see the comment below
 */
int firstMissingPositive(int* nums, int numsSize)
{
	int i;
	for (i = 0; i < numsSize; ++i) {
		// important!! we shuould swap until we get right number(i+1) in the place i
		// Only in this way, we'll not miss some swap by which we place the number we just put before in right place.
		// For example, when i = 2, and nums[i] = 4, nums[3] = 1, we swap(nums, 2, 3), but the 1 we'll never have
		// opportunity to put it in right place.
		while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i]-1]) {
			swap(nums, i, nums[i]-1);
		}
	}

	for (i = 0; i < numsSize; ++i) {
		if (nums[i] != i+1)	 return i+1;
	}

	return n+1;
}

int main()
{
	int n;
	int arr[N];
	while (~scanf("%d", &n)) {
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		printf("The missing positive number is %d\n", firstMissingPositive(arr, n));
	}

	return 0;
}
