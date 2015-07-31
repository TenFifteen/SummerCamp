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
