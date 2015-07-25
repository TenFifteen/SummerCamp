/*
题目大意：
给定一个unix的文件路径的表示，简化它。

解题思路：
使用栈来保存当前的路径，如果遇到了..，就弹出一个。

遇到的问题：
本来我还真没想到/bar//foo/这种情况存在的。
没有其他问题，一次通过。
*/
class Solution {
public:
    string simplifyPath(string path) {
        int cur = 1;
        stack<string> s;
        while(cur < path.size()){
            int front = cur;
            while(front < path.size() && path[front] != '/'){
                front++;
            }
            string str = path.substr(cur, front-cur);
            cur = front+1;
            if(str == "" || str == "."){
                continue;
            }
            if(str == ".."){
                if(!s.empty())s.pop();
            }else{
                s.push(str);
            }
        }
        if(s.empty()){
            return "/";
        }
        stack<string> ans;
        while(!s.empty()){
            string tmp = s.top();
            s.pop();
            ans.push(tmp);
        }
        string ret;
        while(!ans.empty()){
            string tmp = ans.top();
            ans.pop();
            ret += "/"+tmp;
        }
        return ret;
    }
};