/*
题目大意：
给定一个起始字符串，一个终止字符串，一个字典。两个字符串之间有一个字母不同，就可以互相转换。
问是否存在一个字典中的转换，是得start转换到end

解题思路：
深搜找路径，并且记录每个人的fa，而且其fa不一定是一个。

遇到的问题：
没有问题。
*/
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        map<string, vector<string>> fa;
        unordered_set<string> visited;
        vector<vector<string>> ans;
        if(start == end){
            vector<string> tmp;
            tmp.push_back(start);
            ans.push_back(tmp);
            return ans;
        }
        
        fa[start].push_back("");
        visited.insert(start);
        vector<string> cur;
        cur.push_back(start);
        bool finish = false;
        while(cur.size() > 0 && finish == false){
            unordered_set<string> local_v;
            vector<string> next;
            for(int i = 0; i < cur.size(); ++i){
                for(int j = 0; j < cur[i].size(); ++j){
                    for(char ch = 'a'; ch <= 'z'; ++ch){
                        string tmp = cur[i];
                        tmp[j] = ch;
                        if(tmp == end){
                            finish = true;
                            fa[tmp].push_back(cur[i]);
                            continue;
                        }
                        if(dict.count(tmp) > 0 && visited.count(tmp) == 0){
                            fa[tmp].push_back(cur[i]);
                            if(local_v.count(tmp) == 0){
                                local_v.insert(tmp);
                                next.push_back(tmp);
                            }
                        }
                    }
                }
            }
            for(auto v:local_v){
                visited.insert(v);
            }
            if(finish == true){
                vector<string> path;
                path.push_back(end);
                sub(ans, end, fa, path);
            }
            cur = next;
        }
        return ans;
    }
    
    void sub(vector<vector<string>> &ans, string cur, map<string, vector<string>> &fa, vector<string> &path){
        if(fa[cur].size() == 1 && fa[cur][0] == ""){
            vector<string> tmp = path;
            for(int i = 0; i < tmp.size()/2; ++i){
                swap(tmp[i], tmp[tmp.size()-1-i]);
            }
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < fa[cur].size(); ++i){
            path.push_back(fa[cur][i]);
            sub(ans, fa[cur][i], fa, path);
            path.pop_back();
        }
    }
};