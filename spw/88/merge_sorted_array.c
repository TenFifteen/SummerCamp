#include <stdio.h>
#include <stdlib.h>

/**
 * Problem: merge two sorted array list
 * Solve: allocate a temporary array
 * Tips: no
 */
void merge(int* nums1, int m, int* nums2, int n) 
{
	int *nums = malloc(sizeof(int) * (m+n));

	int i = 0, j = 0, k = 0;
	while (i < m && j < n) {
		if (nums1[i] < nums2[j]) {
			nums[k++] = nums1[i++];
		} else {
			nums[k++] = nums2[j++];
		}
	}

	while (i < m) nums[k++] = nums1[i++];
	while (j < n) nums[k++] = nums2[j++];

	while (--k >= 0) nums1[k] = nums[k];
	
	free(nums);
}

int main()
{

}
