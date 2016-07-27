#include <stdio.h>
#include <stdlib.h>


/**
 * Problem: find the peak element, and imagine that nums[-1] = nums[n] = infinite
 * Solve: because nums[-1] = -infinite, then the trend from -1 to 0 is growth,
 *        then we only need to find the first descend element.
 * Tips: in the last return n-1;
 */
int findPeakElement(int* nums, int numsSize)
{
	int i;
	for (i = 1; i < numsSize; ++i) {
		if (nums[i] < nums[i-1]) {
			return i-1;
		}
	}
	return numsSize-1;
}

int main()
{

}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int l = mid - 1 < 0 ? INT_MIN : nums[mid-1];
            int r = mid + 1 >= nums.size() ? INT_MIN : nums[mid+1];

            if (nums[mid] > l && nums[mid] > r) return mid;
            else if (nums[mid] < l) right = mid;
            else left = mid + 1;
        }

        // only one element: INT_MIN
        return 0;
    }
};
