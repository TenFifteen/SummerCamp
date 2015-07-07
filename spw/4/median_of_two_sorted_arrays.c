#include <stdio.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

	int total_size = nums1Size + nums2Size;
	int mid1, mid2;
	if (total_size == 0) return 0.00;
	if (total_size & 1) {
		mid1 = mid2 = total_size / 2;
	} else {
		mid1 = (total_size - 1) / 2;
		mid2 = mid1 + 1;
	}
		printf("mid1=%d, mid2=%d\n", mid1, mid2);

	int i, j, k;
	int f = 0;
	for (i = j = k = 0; i < nums1Size && j < nums2Size && k <= mid1; ++k) {
		if (nums1[i] < nums2[j]) {
			++i;
			f = 0;
		} else {
			++j;
			f = 1;
		}	
	}
	while (i < nums1Size && k <= mid1) {
		++i;
		++k;
		f = 0;
	}
	while (j < nums2Size && k <= mid1) {
		++j;
		++k;
		f = 1;
	}

	if (mid1 ^ mid2) {
		if (f) {
			mid1 = nums2[j-1];	
		} else {
			mid1 = nums1[i-1];
		}

		if (nums1[i] < nums2[j]) {
			mid2 = nums1[i];
		} else {
			mid2 = nums2[j];
		}
		if (i >= nums1Size) 
			mid2 = nums2[j];
		else if (j >= nums2Size)
			mid2 = nums2[i];

		printf("f = %d, i = %d, j = %d, k = %d\n", f, i, j, k);
		printf("mid1=%d, mid2=%d\n", mid1, mid2);
		return (mid2 + mid1) / 2.0;
	}
	
	if(f) return nums2[j-1];
	else return nums1[i-1];
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
