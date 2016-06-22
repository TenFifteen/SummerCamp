#include <stdio.h>


void swap(int v[], int a, int b)
{
	if (v[a] == v[b]) return;
	v[a] = v[a] ^ v[b];
	v[b] = v[a] ^ v[b];
	v[a] = v[a] ^ v[b];
}
void mysort(int v[], int left, int right)
{
	if (left >= right) return;

	swap(v, left, (left+right)/2);
	int last = left, i;
	for (i = left; i <= right; ++i) {
		if (v[i] < v[left]) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);

	mysort(v, left, last-1);
	mysort(v, last+1, right);
}

/**
 * Problem: return the next lexicographically permutation of the specified digit string
 * Solve: find the ascending sequence from the end util we meet an descend one A.
 *        Then we find a digit just above A in the sequence after A.
 *        That is the rule of finding the next permutation.
 *        When the given sequence is the last permutation, we should return the first permutation
 *        , that is the ascending one with all number. This also follow the rule which we can think
 *        as add another digit in the left
 * Tips: see above
 */
void nextPermutation(int* nums, int numsSize)
{
	if (numsSize == 0 || numsSize == 1) return;

	int temp = numsSize - 1, pre = temp - 1;

	while (pre >= 0 && nums[pre] >= nums[temp]) {
		temp--;
		pre--;
	}

	if (pre >= 0) {
		int to_swap = temp, i;
		for (i = temp; i < numsSize; ++i) {
			if (nums[i] > nums[pre] && nums[i] < nums[to_swap]) {
				to_swap = i;
			}
		}
		swap(nums, pre, to_swap);
	}

	mysort(nums, temp, numsSize-1);
}
int main()
{
	int arr[1000];
	int n;
	while (~scanf("%d", &n)) {
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}

		for (i = 0; i < n; ++i) {
			printf("%d ", arr[i]);
		}
		printf("--> ");
		nextPermutation(arr, n);
		for (i = 0; i < n; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

	return 0;
}
