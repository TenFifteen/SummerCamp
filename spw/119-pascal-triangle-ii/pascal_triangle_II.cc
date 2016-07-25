/**
 * Problem: Given an index k, return the kth row of the Pascal's triangle.
 *          optimize your algorithm to use only O(k) extra space.
 * Solve: iteration from the right to left
 * Tips: the k is not the n in last problem.
 */
vector<int> getRow(int rowIndex) {
	vector<int> ans(rowIndex+1, 1);

	for (int i = 1; i <= rowIndex; ++i) {
		for (int j = i-1; j >= 1; --j) {
			ans[j] += ans[j-1];
		}
	}

	return ans;
}

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 1);

        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i-1; j > 0; --j) {
                ans[j] = ans[j] + ans[j-1];
            }
        }

        return ans;
    }
};
