bool isPalin(string &now) {
	int len = now.size();
	if (len < 2) return true;
	for (int i = 0; i < len/2; ++i) {
		if (now[i] != now[len-1-i]) return false;
	}
	return true;
}
void dfs(vector<vector<string> > &ans, vector<string> &now, string &s, int pos) {
	if (pos == s.size()) {
		ans.push_back(now);
		return;
	}

	string word = "";
	for (int i = pos; i < s.size(); ++i) {
		word += s[i];
		if (isPalin(word)) {
			now.push_back(word);
			dfs(ans, now, s, i+1);
			now.pop_back();
		}
	}
}

/**
 * Problem: given a string s, patition s such that every substring of the partition
 *          is a palindrome.
 * Solve: simple back trace
 * Tips: no
 */
vector<vector<string>> partition(string s) {
	vector<vector<string> > ans;
	if (s.empty()) {
		return ans;
	}

	vector<string> now;
	dfs(ans, now, s, 0);
	return ans;
}
