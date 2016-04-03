/**
 * Problem: Given a 2D boolean matrix filled with False and True, find
 *          the largest rectangle containing all True and return its area.
 * Solve: stack
 * Tips: no
 */
class Solution {
    public:
        int findMaxRect(const vector<int> &height) {
            int ans = 0;
            stack<int> index;

            int n = height.size();
            for (int i = 0; i < n; ++i) {
                while (!index.empty() && height[i] <= height[index.top()]) {
                    int h = height[index.top()];
                    index.pop();

                    int begin = index.empty() ? -1 : index.top();

                    ans = max(ans, (i-1-begin)*h);
                }

                index.push(i);
            }

            return ans;
        }

        /**
         * @param matrix a boolean 2D matrix
         * @return an integer
         */
        int maximalRectangle(vector<vector<bool> > &matrix) {
            // Write your code here
            int n = matrix.size();
            if (n == 0) return 0;
            int m = matrix[0].size();

            vector<int> height(m+1, 0);
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!matrix[i][j]) {
                        height[j] = 0;
                    } else {
                        height[j]++;
                    }
                }

                ans = max(ans, findMaxRect(height));
            }

            return ans;
        }
};
