/*
题目大意：
给定一个字典，一个二维的字母表格，问在表格中可以找到哪些字典中的单词。

解题思路：
用字典树+深搜

遇到的问题：
用map实现的字典树，一定要注意不可以随便用[]来索引

再次阅读：
看了一下DISCUSS，这个思路没有什么问题。
只不过感觉代码稍微看起来有些难受。
下次实现的时候，一定要考虑代码的美观。
*/
class Solution {
private:
    struct Node{
        unordered_map<char, Node*> next;
        bool isWord;
        Node(){
            isWord = false;
        }
    };
    Node *root_node;
    void add(string &word){
        auto cur = root_node;
        for(auto w:word){
            if(cur->next.count(w) == 0){
                cur->next[w] = new Node();
            }
            cur = cur->next[w];
        }
        cur->isWord = true;
    }
    void sub(vector<string> &ans, vector<vector<char>> &board, int x, int y, vector<vector<bool>> &flag, Node *root, string &cur){
        if(root->isWord){
            ans.push_back(cur);
            root->isWord = false;
        }
        if(x > 0 && flag[x-1][y] == false && root->next.count(board[x-1][y])){
            flag[x-1][y] = true;
            cur.push_back(board[x-1][y]);
            sub(ans, board, x-1, y, flag, root->next[board[x-1][y]], cur);
            flag[x-1][y] = false;
            cur.pop_back();
        }
        if(y > 0 && flag[x][y-1] == false && root->next.count(board[x][y-1])){
            flag[x][y-1] = true;
            cur.push_back(board[x][y-1]);
            sub(ans, board, x, y-1, flag, root->next[board[x][y-1]], cur);
            cur.pop_back();
            flag[x][y-1] = false;
        }
        if(x + 1 < board.size() && flag[x+1][y] == false && root->next.count(board[x+1][y])){
            flag[x+1][y] = true;
            cur.push_back(board[x+1][y]);
            sub(ans, board, x+1, y, flag, root->next[board[x+1][y]], cur);
            cur.pop_back();
            flag[x+1][y] = false;
        }
        if(y + 1 < board[0].size() && flag[x][y+1] == false && root->next.count(board[x][y+1])){
            flag[x][y+1] = true;
            cur.push_back(board[x][y+1]);
            sub(ans, board, x, y+1, flag, root->next[board[x][y+1]], cur);
            cur.pop_back();
            flag[x][y+1] = false;
        }
    }
public:
    Solution(){
        root_node = new Node();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto w:words){
            add(w);
        }
        vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
        vector<string> ans;
        if(board.size() == 0 || board[0].size() == 0)return ans;
        string cur;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(root_node->next.count(board[i][j])){
                    cur.push_back(board[i][j]);
                    flag[i][j] = true;
                    sub(ans, board, i, j, flag, root_node->next[board[i][j]], cur);
                    cur.pop_back();
                    flag[i][j] = false;
                }
            }
        }
        return ans;
    }
};