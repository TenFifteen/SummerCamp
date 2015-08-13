#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))
/**
 * Problem: Find the minimum health the knight should have, then when he pass
 *          the dugeon, he will always have health point more than one.
 * Sovle: see detail in the discuss board.
 * Tips: 1. in grid, we have two ways of thoughts, from left-top to right-bottom and backwards.
 *       2. the knight at least have 1 after every battle.
 *       3. non-context-related: every time we get the negative need, we just step into an 
 *          new stage with no relation with the backwards.
 */
int calculateMinimumHP(vector<vector<int> >& dungeon) 
{
	int row = dungeon.size();
	int col = dungeon[0].size();

	vector<vector<int> > dp(row+1, vector<int>(col+1, INT_MAX)); 
	dp[row][col-1] = dp[row-1][col] = 1;

	for (int i = row-1; i >= 0; --i) {
		for (int j = col-1; j >= 0; --j) {
			int need = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j];
			dp[i][j] = need <= 0 ? 1 : need;
		}	
	}

	return dp[0][0];
}
int main()
{
	

	return 0;
}
