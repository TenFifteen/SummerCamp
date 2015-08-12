/**
 * Problem: Given an array with n elements, find the majority numbers whoes count more
 *          than n/2
 * Solve: use a guard, and remember its count.
 * Tips: no
 */
int majorityElement(int* nums, int numsSize) {
	if (numsSize == 0) return 0;

	int tag = nums[0];
	int count = 0;
	int i;
	for (i = 0; i < numsSize; ++i) {
		if (count == 0) {
			tag = nums[i];
			count = 1;
		} else {
			nums[i] == tag ? count++ : count--;
		}
	}
	return tag;
}
