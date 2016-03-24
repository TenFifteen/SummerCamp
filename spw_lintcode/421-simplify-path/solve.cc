/**
 * Problem: Given an absolute path for a file (Unix-style), simplify it.
 * Solve: use a stack.
 * Tips: see comments below
 */
class Solution {
    public:
        /**
         * @param path the original path
         * @return the simplified path
         */
        string simplifyPath(string& path) {
            // Write your code here
            stack<string> dirs;

            int n = path.size();
            string dir;
            for (int i = 0; i < n; ++i) {
                if (path[i] == '/') {
                    if (dir != "." && dir != "") {
                        if (dir == "..") {
                            // if dirs.emtpy() don't pop
                            if (!dirs.empty()) dirs.pop();
                        } else {
                            dirs.push(dir);
                        }
                    }

                    // if (dir == ".") we should also clear the dir
                    dir = "";
                } else {
                    dir += path[i];
                }
            }

            // Don't forget to handle the last dir
            if (dir != "." && dir != "") {
                if (dir == "..") {
                    if (!dirs.empty()) dirs.pop();
                } else {
                    dirs.push(dir);
                }
            }


            string ans;
            while (!dirs.empty()) {
                ans = "/" + dirs.top() + ans;
                dirs.pop();
            }

            return ans == "" ? "/" : ans;
        }
};
