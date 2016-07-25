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

class Solution {
public:
    vector<int> getVersion(const string &v) {
        int n = v.size(), i = 0;

        vector<int> ans;
        int d = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] == '.') {
                ans.push_back(d);
                d = 0;
            } else {
                d = d * 10 + (v[i] - '0');
            }
        }
        if (d) ans.push_back(d);

        // pop back the tailing zeros. because we use size to determine in the next
        while (!ans.empty() && ans.back() == 0) ans.pop_back();

        return ans;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = getVersion(version1), v2 = getVersion(version2);

        int i = 0, j = 0, m = v1.size(), n = v2.size();
        while (i < m && j < n) {
            if (v1[i] < v2[j]) return -1;
            else if (v1[i] > v2[j]) return 1;

            ++i, ++j;
        }

        return i == m && j == n ? 0 : i == m ? -1 : 1;
    }
};
