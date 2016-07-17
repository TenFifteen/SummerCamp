#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Problem: Given a 2D binary matrix filled with 0's and 1's, find the
 *          largest rectangle containing all the 1's and return its area.
 * Solve: traversal every row, construct the height histogram, and use the
 *        find the largest rectangle area method to find the final resolution.
 * Tips: no
 */
int largestRectangleArea(vector<int> &height, int size)
{
    stack<int> index;
    int res = 0;

    for (int i = 0; i < size; ++i) {
        while (index.size() > 0 && height[index.top()] >= height[i]) {
            int h = height[index.top()];
            index.pop();

            int start_index = index.size() > 0 ? index.top() : -1;
            int area = h * (i - 1 - start_index);
            if (area > res) res = area;
        }
        index.push(i);
    }
    return res;
}

int maximalRectangle(vector<vector<char> >& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int res = 0;
    vector<int> height(n+1, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '0') {
                height[j] = 0;
            } else {
                height[j]++;
            }
        }
        int now = largestRectangleArea(height, n+1);
        if (now > res) res = now;
    }
    return res;
}

int main()
{

}

class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix.size() <= 0) return 0;
            int m = matrix.size(), n = matrix[0].size();
            vector<int> heights(n+1, 0);
            heights[n] = -1;

            int ans = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    heights[j] = matrix[i][j] == '0' ? 0 : heights[j]+1;
                }

                ans = max(ans, maxArea(heights));
            }

            return ans;
        }

        int maxArea(vector<int> &heights) {
            int n = heights.size(), ans = 0;
            stack<int> index;
            for (int i = 0; i < n; ++i) {
                while (!index.empty() && heights[index.top()] > heights[i]) {
                    int h = heights[index.top()];
                    index.pop();
                    int start = index.empty() ? -1 : index.top();

                    ans = max(ans, h * (i-1-start));
                }
                index.push(i);
            }

            return ans;
        }
};
