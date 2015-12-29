#include <iostream>

using namespace std;

/**
 * Problem: Given a string s and a dictionary of words dict, determine if s can be
 *          segmented into a space-separated sequence of one or more dictionary words.
 * Solve: dp, prefix. O(len(s) * len(s))
 * Tips: no
 */
bool wordBreak(string s, unordered_set<string>& wordDict) {
    if (s == "") return true;
    if (wordDict.size() == 0) return false;

    vector<bool> dp(s.size()+1, false);
    dp[0] = true;

    for (int len = 1; len <= s.size(); ++len) {
        for (int j = len-1; j >= 0; --j) {
            if (dp[j] && wordDict.find(s.substr(j, len-j)) != wordDict.end()) {
                dp[len] = true;
                break;

            }

        }

    }

    return dp[s.size()];

}
