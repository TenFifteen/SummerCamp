#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Promble: find three numbers which add up to zero
 *
 * After sorted, we fetch one number from the vector each time, then we can use
 * the caliper way which have time complexity O(n). We use two pointers, move them
 * from two sides to middle little by little according to the sum of them.
 * We use the property of sorted vecotr that, when the sum is small, we decrease the
 * right pointer, Otherwise, we increase the left pointer.
 *
 * Notice: we must handle the duplicates that may arise.
 * Because we have sorted the vector, then the same number must come up together,
 * When we find a solution, we just need to skip the same numbers in each place.
 */
vector<vector<int> > threeSum(vector<int>& nums)
{
    vector<vector<int> > ans;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int target = -nums[i];

        int start = i + 1, end = n - 1;
        while (start < end) {
            int sum = nums[start] + nums[end];
            if (sum < target) {
                start++;
            } else if (sum > target) {
                end--;
            } else {
                vector<int> traid(3);
                traid[0] = nums[i];
                traid[1] = nums[start];
                traid[2] = nums[end];
                ans.push_back(traid);

                // skip the same nums with the last solution
                // because we have sorted the vector, the same nums get together
                // Processing the duplicates of Number 1 and 2
                while (start < end && nums[start] == traid[1]) start++;
                while (start < end && nums[end] == traid[2]) end--;
            }
        }

        // Processing duplicates of Number 0, we should see the next number, or we will add 1 each time
        while (i+1 < n && nums[i+1] == -target) // WARNING!!! i+1 not i, because we have another i++
            ++i;
    }

    return ans;
}
/**
 * 和原来相比，少了在得到一个结果时候，右边指针的移动。这样是可以的，因为在左边指针移动到不相等的数以后，
 * 右边相等的数肯定就不满足要求了。
 */
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            vector<vector<int>> ans;
            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                int target = 0 - nums[i];
                int left = i+1, right = n-1;
                while (left < right) {
                    if (nums[left] + nums[right] == target) {
                        vector<int> tmp = {nums[i], nums[left], nums[right]};
                        ans.push_back(tmp);
                        while (left+1 < right && nums[left+1] == nums[left]) ++left;
                        ++left;
                    } else if (nums[left] + nums[right] < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }

                while (i+1 < n && nums[i+1] == nums[i]) ++i;
            }

            return ans;
        }
};
int main()
{
	vector<int> nums;
	int n;
	while (~scanf("%d", &n)) {
		printf("+++++++++++++++++++++++++++\n");
		while(n--) {
			int tmp;
			scanf("%d", &tmp);
			nums.push_back(tmp);
		}

		vector<vector<int> > r = threeSum(nums);

		n = r.size();
		for (int i = 0; i < n; ++i) {
			printf("%d %d %d\n", r[i][0], r[i][1], r[i][2]);
		}
		nums.clear();
	}
	return 0;
}
