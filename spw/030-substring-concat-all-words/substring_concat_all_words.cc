#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

/**
 * Problem: You are given a string s, and a list of words, that all of the same length.
 *          Find all starting indices of substring(s) in s that is a concatanation of
 *          each word in words exactly once and without any intervening characters.
 * Solve: use a dict to save the word frequency, then traverse the s string to add up
 *        a continuous string with the same total count and word frequency.
 * Tips: use sliding window method because the words are all of the same width.
 */
vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> ans;
    if (s.size() == 0 || words.size() == 0) return ans;

    unordered_map<string, int> dicts;
    for (int i = 0; i < words.size(); ++i) {
        dicts[words[i]]++;
    }

    int wd = words[0].size();
    int ss = s.size();
    for (int i = 0; i < wd; ++i) {
        int left = i;
        int count = 0;
        unordered_map<string, int> temp;

        for (int j = i; j < ss; j += wd) {
            string now = s.substr(j, wd);
            if (dicts.find(now) != dicts.end()) {
                count++;
                temp[now]++;
                while (temp[now] > dicts[now]) {
                    temp[s.substr(left, wd)]--;
                    left += wd;
                    count--;
                }

                if (count == words.size()) {
                    ans.push_back(left);

                    // need not to be
                    temp[s.substr(left, wd)]--;
                    left += wd;
                    count--;
                }
            } else {
                temp.clear();
                count = 0;
                left = j + wd;
            }
        }
    }

    return ans;
}

/**
 * same solution
 */
class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            unordered_map<string, int> dict;
            for (string w : words) dict[w]++;

            vector<int> ans;
            int n = s.size(), len = words[0].size();
            for (int i = 0; i < len; ++i) {
                int j = i;

                // start = i !
                int total = 0, start = i;
                unordered_map<string, int> tmpDict;
                while (j < n) {
                    string now = s.substr(j, len);

                    if (dict.find(now) != dict.end()) {
                        while (tmpDict[now] >= dict[now]) {
                            string tmp = s.substr(start, len);
                            tmpDict[tmp]--;
                            start += len;
                            total--;
                        }

                        tmpDict[now]++;
                        total++;

                        if (total == words.size()) {
                            ans.push_back(start);
                        }
                    } else {// clear every time encounter a string not in the list
                        start = j + len;
                        total = 0;
                        tmpDict.clear();
                    }

                    j += len;
                }
            }

            return ans;
        }
};
int main()
{
	string s = "barfoothefoobarman";
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");
	findSubstring(s, words);

	return 0;
}
