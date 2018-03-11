#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define N 100
bool used[N];

void sub(vector<vector<int> > &ans, int pos, int n, vector<int> now, vector<int> &nums)
{
	if (pos == n) {
		ans.push_back(now);
		return;
	}

	// traverse all the possible digit
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			used[i] = true;
			now.push_back(nums[i]);
			sub(ans, pos+1, n, now, nums);
			now.pop_back();
			used[i] = false;

			while (i+1 < n && nums[i+1] == nums[i]) ++i;
		}
	}
}

/**
 * Problem: all permutations of a list of numbers.
 * Solve: backtrace after sort
 * Tips: See the comments bellow
 */
vector<vector<int> > permuteUnique(vector<int>& nums) 
{
	vector<vector<int> > ans;
	if (nums.size() == 0) return ans;

	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i){
		used[i] = false;
	}
	vector<int> now;
	sub(ans, 0, nums.size(), now, nums);

	return ans;
}

int main()
{
	int n;
	while (~scanf("%d", &n)) {
		// must be declare in the loop
		vector<int> nums; 
		int temp;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &temp);
			nums.push_back(temp);
		}
		vector<vector<int> > ans = permuteUnique(nums);
		for (int i = 0; i < ans.size(); i++) {
			// notice ans[i].size()
			for (int j = 0; j < ans[i].size(); ++j) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
		printf("================================\n");
	}

	return 0;
}
