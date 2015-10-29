/*
题目：22 % 简化路径 中等

题目大意：
给一个UNIX的路径，将其简化。

解题思路：
栈

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        stack<string> stk;
        if (path.size() == 0) return path;
        int start = 0, end = 0;
        while (start < path.size()) {
            end = start+1;
            while (end < path.size() && path[end] != '/') {
                end++;
            }
            string s = path.substr(start+1, end-start-1);
            start = end;
            if (s == "") continue;
            if (s == ".") continue;
            if (s == "..") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(s);
            }
        }
        stack<string> tmp;
        while (stk.size() > 0) {
            tmp.push(stk.top());
            stk.pop();
        }
        string ans;
        while (tmp.size() > 0) {
            ans.append("/");
            ans.append(tmp.top());
            tmp.pop();
        }
        if (ans == "") {
            return "/";
        } else {
            return ans;
        }
    }
};
