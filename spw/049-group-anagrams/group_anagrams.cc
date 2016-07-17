#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string getKey(string s)
{
	sort(s.begin(), s.end());
	return s;
}

/**
 * Problem: given an array of strings, group anagrams together.
 * Solve: sort the string to get the key.
 * Tips: the C++ init the variable automaticly.
 */
vector<vector<string> > groupAnagrams(vector<string>& strs)
{
	map<string, vector<string> > result;
	vector<vector<string> > ans;
	for (int i = 0; i < strs.size(); ++i) {
		string key = getKey(strs[i]);
		result[key].push_back(strs[i]);
	}

	for (map<string, vector<string> >::iterator it = result.begin(); it != result.end(); ++it) {
		sort(it->second.begin(), it->second.end());
		ans.push_back(it->second);
	}

	return ans;
}

int main()
{
	int count;
	vector<string> strs;
	string str;
	while (cin >> count) {
		for (int i = 0; i < count; ++i) {
			cin >> str;
			strs.push_back(str);
		}

		vector<vector<string> > ans = groupAnagrams(strs);
		for (int i = 0; i < ans.size(); ++i) {
			for (int j = 0; j < ans[i].size(); ++j)	{
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;

        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            table[tmp].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto kv : table) {
            ans.push_back(kv.second);
        }

        return ans;
    }
};
