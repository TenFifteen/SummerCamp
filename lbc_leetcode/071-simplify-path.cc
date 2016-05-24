/*
题目大意：
给定一个unix的文件路径的表示，简化它。

解题思路：
使用栈来保存当前的路径，如果遇到了..，就弹出一个。

遇到的问题：
本来我还真没想到/bar//foo/这种情况存在的。
没有其他问题，一次通过。

再次阅读：
这道题目考察对于栈的使用。对于字符串的操作。
然而看代码的话，还是觉得最后那个stack用的有点没有道理啊。
DISCUSS中有一段代码，实在是简洁，尤其是getline和最后对于stack的遍历我还真没想到。
string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}
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
/*
第二次做：
题目本身比较简单，不过这次写的感觉跟之前写的基本没有什么差别啊。
还是没有用到DISCUSS中那么简洁的写法。
*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> names;
        assert(path.size() > 0 && path[0] == '/');
        
        int last = 0;
        while (last < path.size()) {
            int next = last+1;
            while (next < path.size() && path[next] != '/') next++;
            if (next > last+1) {
                string cur = path.substr(last+1, next-last-1);
                if (cur == "..") {
                    if (names.size() > 0) names.pop();
                } else if (cur != ".") {
                    names.push(cur);
                }
            }
            
            last = next;
        }
        
        if (names.size() == 0) return "/";
        
        vector<string> tmp;
        while (names.size() > 0) {
            tmp.push_back(names.top());
            names.pop();
        }
        string ans;
        for (int i = tmp.size()-1; i >= 0; --i) {
            ans.append("/");
            ans.append(tmp[i]);
        }
        return ans;
    }
};