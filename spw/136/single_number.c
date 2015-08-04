/**
 * Problem: given an array of integers, every elements appears twice except for one,
 *          find that single one.
 * Solve: use exclusive or operator
 * Tips: because the operator XOR satisfy commutative law and associative law
 */
int singleNumber(int* nums, int numsSize) {
	int ans = 0;
	int i;
	for (i = 0; i < numsSize; ++i) {
		ans ^= nums[i];
	}

	return ans;
}
