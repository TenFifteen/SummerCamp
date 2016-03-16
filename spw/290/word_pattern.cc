/**
 * Problem: Given a pattern and a string str, find if str follows the same pattern.
 * Solve: use bijection.
 * Tips: 1. skip unnecessary blansk.
 *       2. if one reach end ahead of the other, return false
 *
 */
class Solution {
    public:
        bool wordPattern(string pattern, string str) {
            unordered_map<char, string> dict;
            unordered_map<string, char> bak;

            int i = 0, b = 0, e = 0;
            for (i = 0; i < pattern.size(); ++i) {
                if (b == str.size()) return false;
                for (e = b; e < str.size() && str[e] != ' '; ++e);

                string now = str.substr(b, e-b);
                b = e; while (b < str.size() && str[b] == ' ') ++b;

                if (dict.find(pattern[i]) == dict.end()) {
                    if (bak.find(now) == bak.end()) {
                        dict[pattern[i]] = now;
                        bak[now] = pattern[i];
                    } else {
                        return false;
                    }
                } else {
                    if (bak.find(now) == bak.end()) {
                        return false;
                    } else {
                        if (bak[now] != pattern[i] || dict[pattern[i]] != now) return false;
                    }
                }
            }

            return i == pattern.size() && b == str.size();
        }
};
