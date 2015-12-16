#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Problem: Given n non-negative integers representing the histogram's bar
 *          height where the width of each bar is 1, find the area of largest
 *          rectangle.
 * Solve: 1. One direct idea is O(n^2) : find the largest area of the rectangle
 *           start with bar[i], that is: maxbar[i] = max{bar[i, j], 0 =< i <= n-1, i =< j <= n-1}
 *           then find the maximum maxbar[i]
 *        2. The other idea is using the stack. We calculate the area of rectangle whose
 *           lowest height is height[i].
 * Tips: we use a stack to remember the index of an increasing  order height of bar. They have the
 *       properties below:
 *       1. The stack[0] is the lowest height of all bar now(0 .. i)
 *       2. The height between index stack[i] and stack[i+1] are all larger than stack[i+1]
 *       that is to say, we use the stack to remember the low frontier of an range.
 */
int largestRectangleArea(vector<int>& height)
{
    height.push_back(-1);
    stack<int> index;
    int res = 0;

    for (int i = 0; i < height.size(); ++i) {
        while (index.size() != 0 && height[index.top()] > height[i]) {
            // find an range whose minimum height is h, which end with
            // i-1(because h>height[i]) and start with the last index
            // in the stack plus one(because the stack keep an increase
            // order of height, and all the height > h have been popped previously).
            int h = height[index.top()];
            index.pop();

            // the index before the rectangle
            // the rectangle start with start_index-1 and end with i-1
            int start_index = index.size() > 0 ? index.top() : -1;
            // the height[index[0]] must be the smallest height now.
            int now_area = (i - 1 - start_index) * h;
            if (now_area > res) res = now_area;
        }
        index.push(i);
    }
    return res;
}

int main()
{

}
