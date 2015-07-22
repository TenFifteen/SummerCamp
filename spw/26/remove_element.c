/**
 * Problem: remove the duplicates int the sorted vector
 * Solve: sth like the two sum, when we skip the duplicate
 * Tips: no
 */
int removeDuplicates(int* nums, int numsSize) {
	int i, count = 0;

	for (i = 0; i < numsSize; ++i) {
		nums[count++] = nums[i];
		while (i+1 < numsSize && nums[i+1] == nums[i]) {
			++i;
		}
	}
	return count;
}
