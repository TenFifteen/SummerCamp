/**
 * Problem: Given a list of numbers with duplicate number in it. Find all unique permutations.
 * Solve: dfs + used vector
 * Tips: see comments below.
 */
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &ans, vector<int> &nums, vector<int> &now, vector<bool> &used) {
    if (now.size() == nums.size()) {
        ans.push_back(now);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            printf("push nums[%d]=%d\n", i, nums[i]);
            used[i] = true; now.push_back(nums[i]);
            dfs(ans, nums, now, used);
            now.pop_back(); used[i] = false;
            // skip the duplicates in the if condition
            while (i+1 < nums.size() && nums[i+1] == nums[i]) ++i;
        }

    }
}
vector<vector<int> > permuteUnique(vector<int> &nums) {
    vector<vector<int> > ans;
    vector<int> now;

    int n = nums.size();
    vector<bool> used(n, false);
    dfs(ans, nums, now, used);
    return ans;
}


int main()
{
    int arr[] = {1, 2, 2};
    vector<int> nums(arr, arr+3);

    permuteUnique(nums);
}
