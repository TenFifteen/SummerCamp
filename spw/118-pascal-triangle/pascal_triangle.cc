/**
 * Problem: Given numRows, generate the first numRows of Pascal's triangle.
 * Solve: iteration
 * Tips: bound
 */
vector<vector<int>> generate(int numRows) {
	vector<vector<int> > ans;
	if (numRows == 0) return ans;

	vector<int> base(1, 1);
	ans.push_back(base);
	for (int i = 2; i <= numRows; ++i) {
		vector<int> line(i, 1);
		// notice j <= i-2
		for (int j = 1; j <= i-2; ++j) {
			line[j] = ans[i-2][j-1] + ans[i-2][j];
		}
		ans.push_back(line);
	}

	return ans;
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; ++i) {
            vector<int> line(i, 1);
            for (int j = 1; j < i-1; ++j) {
                line[j] = ans[i-2][j-1] + ans[i-2][j];
            }
            ans.push_back(line);
        }

        return ans;
    }
};
