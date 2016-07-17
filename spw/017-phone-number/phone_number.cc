#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
char phone_table[10][8] = {
	" ",
	"",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz"
};

/**
 * Problem: covert a number to charater
 * this is a simple dfs
 */
void dfs(vector<string> &ans, string now, string digits, int pos, int n)
{
	if (pos > n-1) {
		ans.push_back(now);
		return;
	}

	int loc = digits[pos]-'0';
	int len = strlen(phone_table[loc]);
	for (int i = 0; i < len; ++i) {
		now += phone_table[loc][i];
		dfs(ans, now, digits, pos+1, n);
		now = now.substr(0, now.size()-1);
	}
}

vector<string> letterCombinations(string digits)
{
	vector<string> ans;
	if (digits.size() == 0) return ans;
	dfs(ans, "", digits, 0, digits.size());

	return ans;
}

/**
* 唯一优化点的地方，就是直接传参数的时候进行now的加和就行。不用加和了在取子串。
*/
class Solution {
public:
    void sub(vector<string> &ans, string tables[], string &digits, int pos, string now) {
        if (pos == digits.size()) {
            ans.push_back(now);
            return;
        }

        string src = tables[digits[pos]-'0'];
        for (int i = 0; i < src.size(); ++i) {
            sub(ans, tables, digits, pos+1, now+src[i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        static string tables[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
            "tuv", "wxyz"};

        vector<string> ans;
        if (digits.empty()) return ans;
        sub(ans, tables, digits, 0, "");
        return ans;
    }
};
int main()
{
	string digits;
	while (cin >> digits) {
		cout << digits << endl;
		vector<string> result = letterCombinations(digits);
		for (int i = 0; i < result.size(); ++i) {
			cout << result[i] << endl;
		}
	}

	return 0;
}
