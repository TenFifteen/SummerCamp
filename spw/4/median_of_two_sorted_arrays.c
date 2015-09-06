#include <stdio.h>


/**
 * Problem: There are two sorted arrays nums1 and nums2 of size m and n respectively. 
 *          Find the median of two sorted arrays, The overall run time complexity 
 *          should be O(log(m+n))
 * Solve: I use the log(n) alogrithm.
 * Tips: see below 
 */
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
	int total_size = nums1Size + nums2Size;
	int mid_pos = (total_size-1) / 2; // Please don't forget to minus 1

	int mid = 0;
	int i = 0, j = 0;
	int flag = 0;
	while (i < nums1Size || j < nums2Size) {
		if (i == nums1Size) {
			flag = 1;
			++j;
		} else if (j == nums2Size || nums1[i] < nums2[j]) {
			flag = 0;
			++i;
		} else {
			flag = 1;
			++j;
		}

		if (i + j == mid_pos+1) {
			if (flag) mid = nums2[j-1];
			else mid = nums1[i-1];
			break;
		}
	}

	if (total_size % 2 == 1) return mid;
	else {
		int mid1 = 0;
		if (i == nums1Size) {
			mid1 = nums2[j];
		} else if (j == nums2Size || nums1[i] < nums2[j]) {
			mid1 = nums1[i];
		} else {
			mid1 = nums2[j];
		}
		return ((double)mid + mid1) / 2;
	}
}

int main()
{
	int m, n;
	int v1[100], v2[1000];
	while (~scanf("%d %d", &m, &n)) {
		int i, j;
		for (i = 0; i < m; ++i) scanf("%d", &v1[i]);
		for (i = 0; i < n; ++i) scanf("%d", &v2[i]);

		double r = findMedianSortedArrays(v1, m, v2, n);
		printf("%.2lf\n", r);
	}

	return 0;
}
