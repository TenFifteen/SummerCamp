#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> > &ans, vector<int> &candidates, vector<int> now, int pos, int left)
{
	if (left == 0) {
		sort(now.begin(),now.end());
		ans.push_back(now);	
		return;
	}

	for (int i = pos; i < candidates.size(); ++i) {
		if (left >= candidates[i]) {
			now.push_back(candidates[i]);
			dfs(ans, candidates, now, i, left-candidates[i]);
			now.pop_back();
		}
	}
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) 
{
	vector<vector<int> > ans;
	vector<int> now;
	dfs(ans, candidates, now, 0, target);

	return ans;
}

int main()
{
	vector<int> c;
	c.push_back(8);
	c.push_back(7);
	c.push_back(4);
	c.push_back(3);

	int target = 11;
	vector<vector<int> > ans = combinationSum(c, target);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}
