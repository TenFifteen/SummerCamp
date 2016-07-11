#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<string> &ans, int pos, int n, string s, string now, int dot)
{
	// either pos or dot can be invalid, but either we should stop dive into
	// 192.168.221. pos == n but dot = 3
	// 1.9.2.168221 dot == 4 but pos != n
	if (pos == n || dot == 4) {
		if (dot == 4 && pos == n)
			ans.push_back(now);
		return;
	}

	int i, num = 0;

	string snum = "";
	for (i = pos; i < n; ++i) {
		num = num * 10 + (s[i] - '0');
		snum += s[i];
		// invalid: 01 or 004
		// i - pos == 0 is of coures vaild, if i - pos > 0
		// then we should make sure that num < 255 and snum[0] != '0'
		if (i-pos == 0 || (num <= 255 && snum[0] != '0')) {
			if (dot < 3)
				dfs(ans, i+1, n, s, now+snum+".", dot+1);
			else
				dfs(ans, i+1, n, s, now+snum, dot+1);
		} else {
			break;
		}
	}
}

/**
 * Problem: Given a string containing only digits,
 *          restore it by returning all possible valid IP address combinations.
 * Solve: backtrace
 * Tips: see comments above
 */
vector<string> restoreIpAddresses(string s)
{
	vector<string> ans;
	if (s.size() < 4) return ans;

	dfs(ans, 0, s.size(), s, "", 0);

	return ans;
}

int main()
{
	string s;
	while (cin >> s) {
		vector<string> r = restoreIpAddresses(s);
		cout << s  << " : " << endl;
		for (int i = 0; i < r.size(); ++i) {
			cout << r[i] << endl;
		}
	}
}
class Solution {
public:
    void dfs(vector<string> &ans, string &s, int word, int pos, string now) {
        int n = s.size();

        if (word == 4) {
            if (pos == n)
                ans.push_back(now);
            return;
        }

        int d = 0;
        for (int i = pos; i < n; ++i) {
            d = d * 10 + (s[i] - '0');
            if (d > 255) return;

            now += s[i];
            if (word == 3)
                dfs(ans, s, word+1, i+1, now);
            else
                dfs(ans, s, word+1, i+1, now+'.');

            if (d == 0) return;
        }

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string now;
        dfs(ans, s, 0, 0, now);

        return ans;
    }
};
