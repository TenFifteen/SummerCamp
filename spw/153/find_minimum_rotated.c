/**
 * Problem: Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * Solve: see below 
 * Tips: see below
 */
int findMin(int* nums, int numsSize) {
	int left = 0, right = numsSize - 1;
	/* this is <= or < was determined which element you return at last.
	nums[right] or nums[left]*/
	while (left < right) {
		int mid = (left + right) / 2;
		/* this is determined by we pretend it is an array without rotated
		then we should compare the mid with the right*/
		if (nums[mid] < nums[right]) {
			/*this because we find the minimum, then we should not miss the smaller one
			 then we will not let the right = mid-1 which will probably miss it*/
			right = mid;
		} else {
			/* because nums[mid] is certainly not the smallest one, that is, the right one
			 must be bigger than it, then we can skip it.*/
			left = mid + 1;
		}
	}

	return nums[right];
}
