#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: line and bottom as a container.
 * Solve: two pointers.
 * Tips: see below
 */
int maxArea(vector<int> &heights) {
    // write your code here
    if (heights.size() <= 1) {
        return 0;
    }

    int l = 0, r = heights.size() - 1;
    int ans = 0;
    while (l < r) {
        int h = min(heights[l], heights[r]);
        ans = max(ans, h * (r - l));

        // because h is the min, then there
        // is only one direction will be move one time.
        while (l < r && heights[l] <= h) ++l;
        while (l < r && heights[r] <= h) --r;
    }

    return ans;
}

int main()
{
    vector<int> h(2, 1);
    cout << maxArea(h) << endl;

    return 0;
}
