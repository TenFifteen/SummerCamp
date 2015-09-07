#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Given an array S of n integers, find three integers in S such that 
 *          the sum is closet to a given number--target. Return the sum of the three
 *          integers, You may asumme that each input would have exactly one solution.
 * Solve: similar way with the 3 sum.
 * Tips: no.
 */
int  threeSumClosest(vector<int>& nums, int target) 
{
	sort(nums.begin(), nums.end());

	int n = nums.size();
	int ans = nums[0] + nums[1] + nums[2];
	int diff = target - ans;

	for (int i = 0; i < n; ++i) {
		int now = target - nums[i];

		int start = i + 1, end = n - 1;
		while (start < end) {
			int sum = nums[start] + nums[end];
			int temp_diff = sum - now;
			if (abs(temp_diff) < abs(diff)) {
				diff = abs(temp_diff);
				ans = sum + nums[i];
			}

			if (sum < now) {
				start++;
			} else if (sum > now) {
				end--;
			} else {
				return ans;				
			}
		}

		// Processing duplicates of Number 0, we should see the next number, or we will add 1 each time
		while (i+1 < n && nums[i+1] == nums[i]) // WARNING!!! i+1 not i, because we have another i++ 
			++i;
	}

	return ans;
}

int main()
{
	vector<int> nums;
	int n, target;
	while (~scanf("%d %d", &n, &target)) {
		printf("+++++++++++++++++++++++++++\n");
		while(n--) {
			int tmp;
			scanf("%d", &tmp);
			nums.push_back(tmp);
		}

		int ans = threeSumClosest(nums, target);

		printf("The result is %d\n", ans);
	}
	return 0;
}
