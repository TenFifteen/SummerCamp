#include <cstdio>
#include <vector>

using namespace std;

/**
 * Problem: find the range in the sorted array of the given number
 * Solve: use targe+0.5 and target-0.5 and find two times
 * Tips: 1. if we use "left=mid" and "left<=mid" we will get endless loop
 *          if we use "left=mid+1" and "left<mid" we will not find the right pos
 *       2. 1 2 3 4 5 7 7 7 7 9
 *          target = 7
 *          if we find 6.5, we will obtain nums[left] = 7, and nums[right] = 5, and right = left - 1;
 *          if we find 7.5, we will obtain nums[left] = 9, and nums[right] = 7, and right = left - 1;
 *
 *          target = 6
 *          if we find 5.5, we will obtain nums[left] = 7, and nums[right] = 5, and right = left - 1;
 *          if we find 6.5, we will obtain nums[left] = 7, and nums[right] = 5, and right = left - 1;
 */
vector<int> searchRange(vector<int>& nums, int target) 
{
	vector<int> range(2);
	range[0] = -1;
	range[1] = -1;

	double a = target - 0.5, b = target + 0.5;
	int left = 0, right = nums.size() - 1;
	int left_boundary, right_boundary;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] < a) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	left_boundary = left;

	left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] < b) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	right_boundary = right;
	if (right_boundary < left_boundary) return range;
	
	range[0] = left_boundary;
	range[1] = right_boundary;
	return range;
}

int main()
{
	int n, target;
	while (~scanf("%d %d", &n, &target)) {
		vector<int> nums;
		for (int i = 0; i < n; ++i) {
			int temp;
			scanf("%d", &temp);
			nums.push_back(temp);
		}
		vector<int> range = searchRange(nums, target);
		printf("%d %d\n", range[0], range[1]);
	}

	return 0;
}
