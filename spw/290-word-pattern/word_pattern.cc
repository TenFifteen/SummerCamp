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

class Solution {
    void split(const string &str, vector<string> &ans) {
        int n = str.size(), i = 0, start = 0;
        while (i < n) {
            if (str[i] == ' ') {
                ans.push_back(str.substr(start, i-start));
                start = i + 1;
            }

            ++i;
        }

        if (start <= i) ans.push_back(str.substr(start, i-start));
    }
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        split(str, words);

        int n = words.size();
        if (n != pattern.size()) return false;

        map<char, string> from;
        unordered_map<string, char> to;
        for (int i = 0; i < n; ++i) {
            auto it1 = from.find(pattern[i]);
            auto it2 = to.find(words[i]);
            if (it1 == from.end() && it2 == to.end()) {
                from[pattern[i]] = words[i];
                to[words[i]] = pattern[i];
            } else if (it1 != from.end() && it2 != to.end()) {
                if (it1->second != words[i] || it2->second != pattern[i])
                    return false;
            } else
                return false;
        }

        return true;
    }
};
