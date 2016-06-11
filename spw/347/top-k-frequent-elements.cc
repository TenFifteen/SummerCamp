/**
 * Problem: Given a non-empty array of integers, return the k most frequent elements.
 * Solve: hashmap + bucket
 * Tips: no
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;

    int maxCnt = 0;
    for (int num : nums) {
        cnt[num]++;
        maxCnt = max(maxCnt, cnt[num]);
    }

    // mind the size:maxCnt+1
    vector<vector<int>> cntBucket(maxCnt+1, vector<int>());
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        cntBucket[it->second].push_back(it->first);
    }

    vector<int> ans;
    for (int i = maxCnt; i > 0 && ans.size() < k; ++i) {
        if (!cntBucket[i].empty())
            ans.insert(ans.end(), cntBucket[i].begin(), cntBucket[i].end());
    }

    while (ans.size() > k) {
        ans.pop_back();
    }

    return ans;
}

int main()
{
    vector<int> data = {1, 1, 1,2,2,3};
    topKFrequent(data, 2);

    return 0;
}

