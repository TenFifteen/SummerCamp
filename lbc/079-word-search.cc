/*
题目大意：
给定一个二维的字母数组，给一个单词，问是否可以在二维表中找到该单词。字母不可重复使用。

解题思路：
采用深度优先搜索加回溯。

遇到的问题：
一开始还没想到深搜，看到题目类型里有回溯，就这么做了。
中间还是遇到了很多边界问题。

再次阅读：
这个题目一看就知道是dfs，之前饿代码也还好。但是在DISCUSS中看到一种可以省掉visited数组的解法：
class Solution {
public:
     bool exist(vector<vector<char> > &board, string word) {
         m=board.size();
         n=board[0].size();
        for(int x=0;x<m;x++)
            for(int y=0;y<n;y++)
            {
                if(isFound(board,word.c_str(),x,y))
                    return true;
            }
        return false;
    }
private:
    int m;
    int n;
    bool isFound(vector<vector<char> > &board, const char* w, int x, int y)
    {
        if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||*w!=board[x][y])
            return false;
        if(*(w+1)=='\0')
            return true;
        char t=board[x][y];
        board[x][y]='\0';
        if(isFound(board,w+1,x-1,y)||isFound(board,w+1,x+1,y)||isFound(board,w+1,x,y-1)||isFound(board,w+1,x,y+1))
            return true; 
        board[x][y]=t;
        return false;
    }
};
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "")return true;
        if(board.size() == 0 || board[0].size() == 0)return false;
        vector<bool> tmp(board[0].size(), false);
        vector<vector<bool>> visited(board.size(), tmp);
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(sub(visited, board, word, i, j))return true;
            }
        }
        return false;
    }
    
    bool sub(vector<vector<bool>> &visited, vector<vector<char>> &board, string word, int x, int y){
        if(board[x][y] == word[0]){
            bool ans = false;
            string nextstr = word.substr(1,word.size()-1);
            if(nextstr == "")return true;
            visited[x][y] = true;
            if(x > 0 && !visited[x-1][y])ans |= sub(visited, board, nextstr, x-1, y);
            if(ans)return true;
            if(x < board.size()-1 && !visited[x+1][y])ans |= sub(visited, board, nextstr, x+1, y);
            if(ans)return true;
            if(y > 0 && !visited[x][y-1])ans |= sub(visited, board, nextstr, x, y-1);
            if(ans)return true;
            if(y < board[0].size()-1 && !visited[x][y+1]) ans |= sub(visited, board, nextstr, x, y+1);
            visited[x][y] = false;
            return ans;
        }else{
            return false;
        }
    }
};