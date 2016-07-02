#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target) 
{
	int left = 0, right = numsSize - 1;		    
	while (left < right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			return mid;
		}

		if (nums[mid] > target) {
			right = mid - 1;
		} else {
			left = mid;
		}
	}
	return -1; 
}

int main()
{
	int n, target;
	while (~scanf("%d %d", &n, &target)) {
		int *arr = malloc(sizeof(int) * (n + 1));
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		printf("The result is %d\n", search(arr, n, target));
	}

	return 0;
}
