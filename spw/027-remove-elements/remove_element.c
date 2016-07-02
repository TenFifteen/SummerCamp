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

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0, n = nums.size();

        for (int i = 0; i < n; ++i) {
            while (i < n && nums[i] == val) ++i;

            if (i < n) nums[pos++] = nums[i];
        }

        return pos;
    }
};
