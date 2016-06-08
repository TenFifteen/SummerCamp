/*
题目大意：
给定一个unix路径，简化。

解题思路：
栈。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        stack<string> s;
        int index = 1, last = 0;
        while (index < path.size()) {
            while (index < path.size() && path[index] != '/') index++;
            if (index - last != 1) {
                string now = path.substr(last+1, index-last-1);
                if (now == "..") {
                    if (s.size() > 0) s.pop();
                } else if (now != ".") {
                    s.push(now);
                }
            }
            last = index;
            index++;
        }
        
        if (s.size() == 0) return "/";
        stack<string> tmp;
        while (s.size() > 0) {
            tmp.push(s.top());
            s.pop();
        }
        
        string ans;
        while (tmp.size() > 0) {
            ans += "/";
            ans += tmp.top();
            tmp.pop();
        }
        
        return ans;
    }
};
