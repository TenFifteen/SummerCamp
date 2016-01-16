#include <iostream>
#include <vector>
#include <unordered_set>

/**
 * Problem: Given a string and a dictionary of words dict, determine if s can
 *          be break into space-separated sequence of one or more dictionary words.
 * Solve: dp over the word length
 * Tips: 1. every time goes before, need not go to zero, but i-max(length(dict))
 *          or when the s is too long and every word of dict is too small, we will
 *          waste a lot of time.
 */
class Solution {
    public:
        /**
         * @param s: A string s
         * @param dict: A dictionary of words dict
         */
        bool wordBreak(string s, unordered_set<string> &dict) {
            int len = 0;
            for (auto w : dict) {
                if (w.size() > len) len = w.size();
            }

            int n = s.size();
            vector<bool> can_break(n+1, false);
            can_break[0] = true;

            for (int i = 1; i <= n; ++i) {
                int start = max(0, i-len);
                for (int j = i-1; j >= start; --j) {
                    can_break[i] = dict.find(s.substr(j, i-j)) != dict.end() && can_break[j];
                    if (can_break[i]) break;
                }
            }

            return can_break[n];
        }
};

int main()
{

}
