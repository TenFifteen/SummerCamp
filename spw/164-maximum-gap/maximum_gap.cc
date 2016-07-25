#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 * Solve: use the idea of bucket sort. Use nums.size() buckets, then the max gap must be the difference of two numbers
 *        in different, because if they are in the same bucket, there must an empty bucket, the numbers lay nearby must
 *        have bigger difference.
 * Tips: see below
 */
int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;

    int max_num = nums[0];
    int min_num = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        max_num = max(max_num, nums[i]);
        min_num = min(min_num, nums[i]);
    }

    int total_range = max_num - min_num + 1;
    int bucket_size = total_range / n;
    if (total_range % n) bucket_size++;

    vector<int> buckets_min(n, max_num);
    vector<int> buckets_max(n, min_num);

    for (int i = 0; i < n; ++i) {
        int bucket_id = (nums[i] - min_num) / bucket_size;
        buckets_min[bucket_id] = min(buckets_min[bucket_id], nums[i]);
        buckets_max[bucket_id] = max(buckets_max[bucket_id], nums[i]);
    }

    // last_min hold last non-empty max number
    // then we use the min number of this bucket minus it to get the biggest gap
    int last_min = max_num;
    int max_gap = 0;
    for (int i = 0; i < n; ++i) {
        if (buckets_min[i] != max_num) {
            max_gap = max(max_gap, buckets_min[i] - last_min);
            last_min = buckets_max[i];
        }
    }

    return max_gap;
}

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int temp;
            scanf("%d", &temp);
            nums.push_back(temp);
        }
        printf("The maximum gap is %d\n", maximumGap(nums));
    }
    return 0;
}


class Solution {
    public:
        int maximumGap(vector<int>& nums) {
            int n = nums.size();
            if (n < 2) return 0;

            vector<pair<int, int>> buckets(n, make_pair(INT_MAX, INT_MIN));
            int maxEle = nums[0], minEle = nums[0];
            for (int i = 1; i < n; ++i) {
                maxEle = max(maxEle, nums[i]);
                minEle = min(minEle, nums[i]);
            }

            int interval = (maxEle - minEle + n) / n;
            for (int i = 0; i < n; ++i) {
                int bi = (nums[i] - minEle) / interval;
                buckets[bi].first = min(nums[i], buckets[bi].first);
                buckets[bi].second = max(nums[i], buckets[bi].second);
            }

            int ans = 0, prev = minEle;
            for (int i = 0; i < n; ++i) {
                // empty bucket
                if (buckets[i].first == INT_MAX && buckets[i].second == INT_MIN) continue;

                // the max gap must exist in two buckets, because if there are two elements
                // in one bucket, according to pigeonhole principle, there must be empty bucket.
                ans = max(ans, buckets[i].first - prev);
                prev = buckets[i].second;
            }

            return ans;
        }
};
