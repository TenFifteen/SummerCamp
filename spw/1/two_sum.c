#include <stdio.h>
#include <stdlib.h>

void swap(int v[], int left, int right)
{
	if (left == right) return;
	v[left] = v[left] ^ v[right];
	v[right] = v[left] ^ v[right];
	v[left] = v[left] ^ v[right];
}
void mysort(int v[], int loc[], int left, int right)
{
	if (left >= right) return;

	int i, last = left;
	swap(v, left, (left+right)/2);
	swap(loc, left, (left+right)/2);
	for (i = left+1; i <= right; ++i) {
		if (v[i] < v[left]) {
			swap(v, i, ++last);
			swap(loc, i, last);
		}
	}
	swap(v, last, left);
	swap(loc, last, left);

	mysort(v, loc, left, last-1);
	mysort(v, loc, last+1, right);
}

int* twoSum(int* nums, int numsSize, int target) 
{
	int *result = malloc (sizeof(int) * 2);

	int *loc = malloc(sizeof(int) * (numsSize + 1));
	int i, j;
	for (i = 0; i < numsSize; ++i) {
		loc[i] = i;
	}
	
	mysort(nums, loc, 0, numsSize-1);
	for (i = 0; i < numsSize; ++i) {
		//if (nums[i] >= target) continue;
		int s = i + 1, e = numsSize - 1;
		int a = target - nums[i];
		if (a < nums[s] || a > nums[e]) continue;

		while (e >= s) {
			int mid = (s + e) / 2;
			if (nums[mid] == a) {
				result[0] = loc[i]+1;
				result[1] = loc[mid]+1;
				free(loc);
				if (result[0] > result[1]) swap(result, 0, 1);
				return result;
			} else if (nums[mid] > a) {
				e = mid ;
			} else {
				s = mid ;	
			}
		}
	}
}

int main()
{
	int n, target;
	int array[1000];
	while (~scanf("%d %d", &n, &target)) {
		int i;
		for (i = 0; i < n; ++i) {
			scanf("%d", &array[i]);
		}
		int *result = twoSum(array, n, target);
		printf("index1=%d, index2=%d\n", result[0], result[1]);
		free(result);
	}

	return 0;
}
