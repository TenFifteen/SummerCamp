#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Given an array S of n integers, are there elements a, b, c, d in S such that
 *          a + b + c + d = target.
 * Solve: same way with 3Sum.
 * Tips: no
 */
vector<vector<int> > fourSum(vector<int>& nums, int target)
{
    vector<vector<int> > ans;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int now = target - nums[i] - nums[j];

            int start = j + 1, end = n - 1;
            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum < now) {
                    start++;
                } else if (sum > now) {
                    end--;
                } else {
                    vector<int> tetrad(4);
                    tetrad[0] = nums[i];
                    tetrad[1] = nums[j];
                    tetrad[2] = nums[start];
                    tetrad[3] = nums[end];
                    ans.push_back(tetrad);

                    // skip the same nums with the last solution
                    // because we have sorted the vector, the same nums get together
                    // Processing the duplicates of Number 1 and 2
                    while (start < end && nums[start] == tetrad[2]) start++;
                    while (start < end && nums[end] == tetrad[3]) end--;
                }
            }

            while (j+1 < n && nums[j+1] == nums[j]) // WARNING!!! i+1 not i, because we have another i++
                ++j;
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

        vector<vector<int> > r = fourSum(nums, target);

        n = r.size();
        for (int i = 0; i < n; ++i) {
            printf("%d %d %d %d\n", r[i][0], r[i][1], r[i][2], r[i][3]);
        }
        nums.clear();
    }
    return 0;
}

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());

            int n = nums.size();
            vector<vector<int>> ans;
            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    int t = nums[i] + nums[j];
                    t = target - t;
                    int left = j + 1, right = n - 1;
                    while (left < right) {
                        if (nums[left] + nums[right] == t) {
                            vector<int> tmp = {nums[i], nums[j], nums[left], nums[right]};
                            ans.push_back(tmp);

                            while (left+1 < right && nums[left+1] == nums[left]) ++left;
                            ++left;
                        } else if (nums[left] + nums[right] < t) ++left;
                        else --right;
                    }

                    while (j+1 < n && nums[j+1] == nums[j]) ++j;
                }
                while (i+1 < n && nums[i+1] == nums[i]) ++i;
            }

            return ans;
        }
};
