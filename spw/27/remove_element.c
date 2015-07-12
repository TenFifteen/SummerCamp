#include <stdio.h>


/**
 * Problem: remove the specified duplicates
 * Solve: nothing to say
 * Tips: none
 */
int removeElement(int* nums, int numsSize, int val) 
{
	int i, count = 0;

	for (i = 0; i < numsSize; ++i) {
		if (nums[i] != val) {
			nums[count++] = nums[i];
		}
	}

	return count;
}

int main()
{

}
