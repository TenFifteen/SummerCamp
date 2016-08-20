#include <string>
#include <iostream>
#include <vector>
#include <map>


using namespace std;
map<char, int> m;
/**
 * Problem: Write a function to find all the 10-letter long sequences(substring) that occur
 *          more than once in the DNA(only contains A, C, G and T)
 * Solve: key point, find a proper hash function.
 * Tips: don't calculate the key of ten-letter each time. We only need slide the 10-letter
 *       window each time.
 */
/*origin*/
vector<string> findRepeatedDnaSequences(string s)
{
	vector<string> ans;
	int n = s.size();
	if (n < 10) return ans;

	m['A'] = 0;
	m['C'] = 1;
	m['G'] = 2;
	m['T'] = 3;
	map<int, int> count;
	for (int i = 0; i <= n-10; ++i) {
		int kn = 0;
		for (int j = 0; j < 10; ++j) {
			kn = (kn<<2) + m[s[i+j]];
		}

		if (count[kn]++ == 1)
			ans.push_back(s.substr(i, 10));
		cout << s.substr(i, 10) << " : " << kn << endl;
		cout << kn << " : "  << count[kn] << endl;
	}
	return ans;
}
/**
 * find in the discuss board, ideas:
 * A:0x41 B:0x43 G:0x47 T:0x54
 * use three bit to represent an letter.
 * */
vector<string> findRepeatedDnaSequences(string s)
{
	vector<string> ans;
	int n = s.size();
	if (n < 10) return ans;

	unordered_map<int, int> count;
	int k = 0;
	int i = 0;
	while (i < 9) {
		k = (k<<3) | s[i++] & 0x7;
	}

	while (i < n) {
		if (count[k = (k<<3) & 0x3FFFFFFF | s[i++] & 0x7]++ == 1) {
			ans.push_back(s.substr(i-10, 10));
		}
	}
	return ans;
}
/**
 * also find in the discuss board.
 * use only two bit, then the hash map can use an array because of
 * the much smaller range of the key.
 **/
vector<string> findRepeatedDnaSequences1(string s)
{
	vector<string> ans;
	int n = s.size();
	if (n < 11) return ans;

	int  count[1048576] = {0}; // 2^20: we can represent: 0 ~ 2^20-1
	int k = 0;
	int i = 0;
	while (i < 9) {
		k = (k<<2) | (s[i++]-'A'+1)%5;
	}

	while (i < n) {
		if (count[k = (k<<2) & 0xFFFFF | (s[i++]-'A'+1)%5]++ == 1) {
			ans.push_back(s.substr(i-10, 10));// i-10 because we use i++ above.
		}
	}
	return ans;
}

int main()
{
	string s;
	while (cin >> s) {
		cout << "====================" << endl;
		cout << "The repeated DNA in " << s
			<< " is:" << endl;
		vector<string> ans = findRepeatedDnaSequences(s);
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i] << " ";
		}
		cout << endl;
		cout << "====================" << endl;
	}

	return 0;
}


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> dict;
        vector<string> ans;
        int n = s.size();
        for (int i = 0; i <= n-10; ++i) {
            string now = s.substr(i, 10);
            if (dict.find(now) == dict.end())
                dict[now] = 1;
            else if (dict[now] == 1) {
                ans.push_back(now);
                dict[now]++;
            }
        }

        return ans;
    }
};
