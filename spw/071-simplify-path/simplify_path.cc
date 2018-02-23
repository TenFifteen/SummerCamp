#include <cstdio>
#include <string>
#include <vector>

using namespace std;
/**
 * Problem: Given an absolute path for a file (Unix-style), simplify it.
 * Solve: stack
 * Tips: 1. /.. => /
 *       2. /. => /
 *       3. /// => /
 *       4. / => /
 */
class Solution {
	public:
		string simplifyPath(string path) {
			if (path == "" ) return path;

			int len = path.size();
			vector<string> folders;
			string folder = "";
			for (int i = 0; i < len; ++i) {
				if (path[i] == '/') {
					if (folder == "..") {
						if (!folders.empty())
							folders.pop_back();
					} else {
						if (folder != "" && folder != ".") {
							folders.push_back(folder);
						}
					}

					folder = "";
				} else {
					folder += path[i];
				}
			}

			if (folder == "..") {
				if (!folders.empty())
					folders.pop_back();
			} else {
				if (folder != "" && folder != ".") {
					folders.push_back(folder);
				}
			}

			string ans = "";
			for (auto temp : folders) {
				ans += "/" + temp;
			}

			if (ans == "") ans = "/";
			return ans;
		}
};

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;

        int i = 0, n = path.size();

        if (i < n && path[i] == '/') ++i;

        while (i < n) {
            int j = i;
            while (j < n && path[j] != '/')
                ++j;
            string now = path.substr(i, j-i);

            if (now == "..") {
                if (!s.empty())
                    s.pop();
            }
            else if (now != "." && now != "")
                s.push(now);

            i = j + 1;
        }

        string ans;
        while (!s.empty()) {
            ans =  '/' + s.top() + ans;
            s.pop();
        }

        if (ans.empty())
            ans = "/";

        return ans;
    }

};

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> folders;
        int i = 0, n = path.size();

        while (i < n) {
            if (path[i] == '/') {
                int j = i + 1;
                while (j < n && path[j] != '/') ++j;

                string now = path.substr(i+1, j-i-1);
                if (now == ".." ) {
                    if (!folders.empty()) folders.pop_back();
                } else if (now != "." && now != "") {
                    folders.push_back(now);
                }

                i = j;
            } else {
                ++i;
            }
        }

        string res;
        for (int i = 0; i < folders.size(); ++i) {
            res += "/" + folders[i];
        }

        return res == "" ? "/" : res;
    }
};
