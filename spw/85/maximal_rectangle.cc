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
