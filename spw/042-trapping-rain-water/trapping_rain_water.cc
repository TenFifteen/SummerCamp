#include <cstdio>
#include <vector>

using namespace std;

/**
 * Problem: trapping water
 * Solve: find the highest voted in the discuss board
 * Tips:
 */
int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int max_left = 0, max_right = 0;
    int ans = 0;

    while (left <= right) {
        // each time the lower side is moving
        // the other side is in the highest
        if (height[left] <= height[right]) {
            // we can put the == in each branch
            if (height[left] >= max_left) max_left = height[left];
            else ans += max_left - height[left];
            left++;
        } else {
            if (height[right] >= max_right) max_right = height[right];
            else ans += max_right - height[right];
            right--;
        }
    }

    return ans;
}

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        vector<int> h(n+1);
        int temp;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &temp);
            h[i] = temp;
            printf("%d ", h[i]);
        }
        int r = trap(h);
        printf("r = %d\n", r);
    }

    return 0;
}
class Solution {
    public:
        int trap(vector<int>& height) {
            if (height.size() < 3) return 0;
            int left = 0, right = height.size() - 1;

            int h = min(height[left], height[right]);
            if (height[left] < height[right]) ++left;
            else --right;

            int ans = 0;
            while (left < right) {
                while (left < right && height[left] <= height[right]) {
                    h = max(h, height[left]);
                    ans += h - height[left];
                    ++left;
                }

                while (left < right && height[left] >= height[right]) {
                    h = max(h, height[right]);
                    ans += h - height[right];
                    --right;
                }
            }

            return ans;
        }
};
