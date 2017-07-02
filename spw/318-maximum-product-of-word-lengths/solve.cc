/**
 * Problem: Given a string array words, find the maximum value of length(word[i]) * length(word[j])
 *          where the two words do not share common letters. You may assume that each word will
 *          contain only lower case letters. If no such two words exist, return 0.
 * Solve: just do it
 * Tips: no
 */
class Solution {
    public:
        int maxProduct(vector<string>& words) {
            vector<unordered_set<int>> table(26, unordered_set<int>());

            int n = words.size();
            for (int i = 0; i < n; ++i) {
                for (char &c : words[i]) {
                    table[c-'a'].insert(i);
                }
            }

            int res = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    bool doesShare = false;
                    for (char &c : words[i]) {
                        if (table[c-'a'].find(j) != table[c-'a'].end()) {
                            doesShare = true;
                            break;
                        }
                    }
                    if (!doesShare) {
                        res = max(res, (int)words[i].length() * (int)words[j].length());
                    }
                }
            }

            return res;
        }
};

class Solution {
    public:
        int maxProduct(vector<string>& words) {
            int n = words.size();
            if (n < 2) return 0;

            vector<unsigned int> bitmap(n, 0);
            for (int i = 0; i < n; ++i) {
                for (char c : words[i]) {
                    bitmap[i] |= 1 << c - 'a';
                }
            }

            int res  = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    if ((bitmap[i] & ~bitmap[j]) == bitmap[i])
                        res = max(res, (int)words[i].size() * (int)words[j].size());
                }
            }

            return res;
        }
};
