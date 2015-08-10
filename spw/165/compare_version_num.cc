/**
 * Problem: compare two version numbers version1 and version2. For example:
 *          0.1 < 1.1 < 1.2 < 13.37
 * Solve: split and compare
 * Tips: 1.0 and 1
 */
vector<int> split_version(string version) {
	vector<int> ans;
	int n = version.size();
	string now = "";
	for (int i = 0; i < n; ++i) {
		if (version[i] == '.') {
			ans.push_back(stoi(now));
			now = "";
			continue;
		}
		now += version[i];
	}
	ans.push_back(stoi(now));
	return ans;
}

int compareVersion(string version1, string version2) {
	vector<int> v1 = split_version(version1);
	vector<int> v2 = split_version(version2);

	int len1 = v1.size();
	int len2 = v2.size();

	int i = 0;
	while (i < len1 && i < len2 && v1[i] == v2[i]) ++i;
	if (i < len1 && i < len2) {
		if (v1[i] > v2[i]) return 1;
		else if (v1[i] < v2[i]) return -1;
		return 0;
	} else if (i < len1) {
		while (i < len1) {
			if (v1[i] != 0) {
				return 1;
			}
			++i;
		}
		return 0;
	} else if (i < len2) {
		while (i < len2) {
			if (v2[i] != 0) {
				return -1;
			}
			++i;
		}
		return 0;
	}
	return 0;
}
