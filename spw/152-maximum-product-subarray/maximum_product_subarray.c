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
			/*
			if (negative_product != 0){
				positive_product = negative_product * nums[i];
			} else {
				positive_product = 0;
			}*/
			positive_product = max(n*nums[i], nums[i]);

			// negative product
			negative_product = min(nums[i], nums[i]*p);
		} else if (nums[i] > 0) {
			flag = 1;
			// positive product
			/*
			if (positive_product == 0) {
				positive_product = nums[i];
			} else {
				positive_product = positive_product * nums[i];
			}*/
			positive_product = max(nums[i], nums[i]*positive_product);

			// negative product
			/*if (negative_product != 0){
				negative_product = negative_product * nums[i];
			} */
			negative_product = negative_product * nums[i];
		} else {
			positive_product = 0;
			negative_product = 0;
		}
		if (flag || positive_product > 0) max_product = max(max_product, positive_product);
		else max_product = max(max_product, negative_product);
	}
	return max_product;
}

/**
 * attach one from the discuss board
 */
int maxProduct1(int A[], int n) {
	if (n == 0) return 0;
	int maxProduct = A[0];
	int minProduct = A[0];
	int maxRes = A[0];
	for (int i = 1; i < n; i++)
	{
		if (A[i] >= 0)
		{
			maxProduct = max(maxProduct * A[i], A[i]);
			minProduct = min(minProduct * A[i], A[i]);
		}
		else
		{
			int temp = maxProduct;
			maxProduct = max(minProduct * A[i], A[i]);
			minProduct = min(temp * A[i], A[i]);
		}
		maxRes = max(maxRes, maxProduct);
	}
	return maxRes;
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


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int po = 0, neg = 0;
        int n = nums.size();
        if (n <= 0) return 0;
// the only bad case
        if (n == 1 && nums[0] <= 0) return nums[0];


        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                int tn = neg;
                neg = min(nums[i], po*nums[i]);
                po = tn * nums[i];
            } else if (nums[i] > 0){
                po = max(nums[i], po*nums[i]);
                neg = nums[i]*neg;
            } else {
                po = neg = 0;
            }

            ans = max(ans, po);
        }

        return ans;
    }
};
