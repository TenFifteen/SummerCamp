/**
 * @param heights: a vector of integers
 * @return: a integer
 */
/**
 * Tips: see comments below.
 */
int trapRainWater(vector<int> &heights) {
    if (heights.size() <= 2) return 0;

    int left = 0, right = heights.size() - 1;
    int max_left = heights[left], max_right = heights[right];

    int ans = 0;
    // must have =, because we calculate left or right each time,
    // if we don't have =, then the last one(where left = count), we will not count.
    while (left <= right) {
        // we move the low height every time
        // We count one grid each time. The water this gird will take depends on
        // the left one peak pillar and the right one peak pillar, but finally
        // it depends the difference between this grid and the lower peak one.
        if (max_left <= max_right) {
            max_left = max(max_left, heights[left]);
            ans += (max_left - heights[left]);
            ++left;
        } else {
            max_right = max(max_right, heights[right]);
            ans += (max_right - heights[right]);
            --right;
        }
    }

    return ans;
}
