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
/*
第二次做：
题目算是比较复杂了，不过由于是早上的第一道题，所以做的还是挺顺利的。
*/
class Solution {
private:
    class TrieNode {
    public:
        bool isWord;
        TrieNode* next[26];
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; ++i) next[i] = NULL;
        }
    };
    
    TrieNode *root;
    
    void insert(const string &word) {
        TrieNode *cur = root;
        for (auto ch : word) {
            if (cur->next[ch-'a'] == NULL) {
                cur->next[ch-'a'] = new TrieNode();
            }
            cur = cur->next[ch-'a'];
        }
        cur->isWord = true;
    }
    
    void destroy() {
        queue<TrieNode *> q;
        q.push(root);
        
        while (q.size() > 0) {
            auto cur = q.front(); q.pop();
            for (int i = 0; i < 26; ++i) {
                if (cur->next[i] != NULL) q.push(cur->next[i]);
            }
            delete cur;
        }
    }
    
    void search(vector<vector<char>> &board, vector<string> &ans, string now, int x, int y, TrieNode* r) {
        if (r->isWord) {
            ans.push_back(now);
            r->isWord = false;
        }
        
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() 
        || board[x][y] == 0 || r->next[board[x][y]-'a'] == NULL) return;
        
        const int ix[] = {-1, 0, 1, 0};
        const int iy[] = {0, -1, 0, 1};
        
        char old = board[x][y];
        board[x][y] = 0;
        now.push_back(old);
        for (int i = 0; i < 4; ++i) {
            search(board, ans, now, x+ix[i], y+iy[i], r->next[old-'a']);
        }
        board[x][y] = old;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            insert(words[i]);
        }
        
        vector<string> ans;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                search(board, ans, "", i, j, root);
            }
        }
        
        destroy();
        return ans;
    }
};