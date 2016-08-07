/*
 * ok, but there exist better answer.
 * actually, it is like longest increasing subsequence.
 * https://discuss.leetcode.com/topic/47469/java-nlogn-solution-with-explanation
 */
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() == 0) return 0;
        sort(envelopes.begin(), envelopes.end());

        vector<int> dp(envelopes.size(), 1);
        vector<int> count(dp);
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second) {
                    dp[i] = max(dp[j]+1, dp[i]);
                    if (dp[j] == count[j]) break;
                }
            }
            count[i] = max(count[i-1], dp[i]);
        }
        return count.back();
    }
};
