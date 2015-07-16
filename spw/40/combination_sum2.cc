#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Given a collection of candidate numbers (C) and a target number (T), 
 *          find all unique combinations in C where the candidate numbers sums to T.
 *          Each number in C may only be used once in the combination.
 * Solve: 1. duplicates: sort the candidates beforehand, and add the pos when dfs
 *           each time after call dfs, we skip the same numbsers.
 * Tips: add pos when call dfs other than i = pos+1
 */
void dfs(vector<vector<int> > &ans, vector<int> &candidates, vector<int> now, int pos, int left)
{
	if (left == 0) {
		ans.push_back(now);	
		return;
	}

	for (int i = pos; i < candidates.size(); ++i) {
		if (left >= candidates[i]) {
			now.push_back(candidates[i]);
			dfs(ans, candidates, now, i+1, left-candidates[i]);
			now.pop_back();
			// important!! associated with the sort(candidates.begin(), candidates.end())
			while (i+1 < candidates.size() && candidates[i+1] == candidates[i]) ++i;
		}
	}
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) 
{
	vector<vector<int> > ans;
	vector<int> now;
	sort(candidates.begin(),candidates.end());
	dfs(ans, candidates, now, 0, target);

	return ans;
}

int main()
{
	int n, target, temp;
	while (~scanf("%d %d", &n, &target)) {
		vector<int> c;
		while (n--) {
			scanf("%d", &temp);
			c.push_back(temp);
		}

		vector<vector<int> > ans = combinationSum(c, target);
		for (int i = 0; i < ans.size(); ++i) {
			for (int j = 0; j < ans[i].size(); ++j) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
	}



	return 0;
}
