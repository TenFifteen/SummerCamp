#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int maxProduct(int* nums, int numsSize) {
	if (numsSize < 1) return 0;
	int positive_product = 0;
	int negative_product = 0;

	int i;
	int max_product = (0x1 << 31);
	int flag = 0;
	for (i = 0; i < numsSize; ++i) {
		int p = positive_product, n = negative_product;
		if (nums[i] < 0) {
			// positive product
			if (negative_product != 0){
				positive_product = negative_product * nums[i];
			} else {
				positive_product = 0;
			}

			// negative product
			negative_product = min(nums[i], nums[i]*p);
		} else if (nums[i] > 0) {
			flag = 1;
			// positive product
			if (positive_product == 0) {
				positive_product = nums[i];
			} else {
				positive_product = positive_product * nums[i];
			}

			// negative product
			if (negative_product != 0){
				negative_product = negative_product * nums[i];
			} 
		} else {
			positive_product = 0;
			negative_product = 0;
		}
		if (flag || positive_product > 0) max_product = max(max_product, positive_product);
		else max_product = max(max_product, negative_product);
	}
	return max_product;
}

int main()
{
	int arr[100];
	int n;
	while (~scanf("%d", &n)) {
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			printf("%d ", arr[i]);
		}
		printf("\n");
		printf("The max product is %d\n", maxProduct(arr, n));
	}

	return 0;
}
