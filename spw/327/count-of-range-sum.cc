/**
 * Problem: Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
 * Solve: Get the count when do merge sort
 *       1.Only get the first sum[i] in the left vector, and sum[j] in the right vector, which can keep
 *         the origin order.
 *       2. Every time we can get O(n) time complexity because the right vector is in order.
 * Tips: 1. see comments below.
 */
class Solution {
    int cntMergeSort(vector<long long> &sum, int left, int right, int lo, int up) {
        if (left >= right) return 0;

        int mid = (left + right) / 2;
        int cnt = cntMergeSort(sum, left, mid, lo, up) + cntMergeSort(sum, mid+1, right, lo, up);

        int a = mid+1, b = mid+1;
        // this is O(n), because a and b do not go back any time.
        for (int i = left; i <= mid; ++i) {
            // we get [a, b) in the end. because b will probably get out of range. Then b
            // must not inclusive.
            while (b <= right && sum[b]-sum[i] <= up) b++;
            while (a <= right && sum[a]-sum[i] < lo) a++;

            cnt += (b-a);
        }

        vector<long long> tmp(right-left+1);
        int i = left, j = mid+1;
        int pos = 0;
        while (i <= mid || j <= right) {
            if (j > right || i <= mid && sum[i] < sum[j]) tmp[pos++] = sum[i++];
            else tmp[pos++] = sum[j++];
        }
        pos = left-1;
        while (++pos <= right) sum[pos] = tmp[pos-left];

        return cnt;
    }
    public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n == 0) return 0;

        // must use long long
        vector<long long> sum(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1] + nums[i-1];
        }

        return cntMergeSort(sum, 0, n, lower, upper);
    }
};
