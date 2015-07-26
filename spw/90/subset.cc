#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> > &ans, int pos, int n, int len, vector<int> now, vector<int> &nums)
{
	if (now.size() == len) {
		ans.push_back(now);
		return;
	}

	// every time we select a number as now[j], j = 0...len-1
	// every time we have serveral choices: nums[i], i = pos...n-1
	// So we need notice that if we select number 'a' in now[j]
	// we should avoid selecting other 'a' int now[j]
	for (int i = pos; i < n; ++i) {
		now.push_back(nums[i]);
		dfs(ans, i+1, n, len, now, nums);
		now.pop_back();
		// skip other nums[i]
		while (i+1 < n && nums[i+1] == nums[i]) ++i;
	}
}

/**
 * Problem: Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 * Sovle: backtrace 
 * Tips: trverse every posible lenght(notice 0) 
 */
vector<vector<int> > subsetsWithDup(vector<int>& nums) 
{
	vector<vector<int> > ans;
	sort(nums.begin(), nums.end());
	for (int len = 0; len <= nums.size(); len++) {
		vector<int> now;
		dfs(ans, 0, nums.size(), len, now, nums);
	}

	return ans;
}

int main()
{
	int n;
	while (cin >> n) {
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) {
			int temp;
			cin >> temp;
			nums[i] = temp;
		}
		vector<vector<int> > ans = subsetsWithDup(nums);

		cout << "-----------------" << endl;
		for (int i = 0; i < ans.size(); ++i) {
			for (int j = 0; j < ans[i].size(); ++j) {
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
