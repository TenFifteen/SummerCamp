/*
题目大意：
给定一个二维的表格，其中是X或者是O。如果一个O被X包围，那么O也就要变成X。

解题思路：
一看就是个搜索。BFS

遇到的问题：
这个题目可是折腾死我了。
一开始用的递归的方式，结果竟然一直是运行时错误。找了好久都没找到错误。感觉有可能是递归深度太深了，
导致栈不够用了。
然后开始用非递归的方式。然后就是一直在错。找了好久还是没找出来。
最后看别人的方法，就是绕着二维表外边遍历一遍，找到所有的可以不被包围的点，其他的就都是被包围的了。
然后又错了一次才终于AC了。

看来今天实在是不适合写代码啊。这个题的代码太乱了。回头还要再好好的写一下。

再次阅读：
这次最初的想法还是跟上次一样，但是从里面往外面搜索代价会大一些。
如果是从边缘往里面搜索的话，不需要记录状态，直接修改就行。所以还是用这种方式比较靠谱：
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int i,j;
        int row=board.size();
        if(!row)
            return;
        int col=board[0].size();

        for(i=0;i<row;i++){
            check(board,i,0,row,col);
            if(col>1)
                check(board,i,col-1,row,col);
        }
        for(j=1;j+1<col;j++){
            check(board,0,j,row,col);
            if(row>1)
                check(board,row-1,j,row,col);
        }
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                if(board[i][j]=='O')
                    board[i][j]='X';
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                if(board[i][j]=='1')
                    board[i][j]='O';
    }
    void check(vector<vector<char> >&vec,int i,int j,int row,int col){
        if(vec[i][j]=='O'){
            vec[i][j]='1';
            if(i>1)
                check(vec,i-1,j,row,col);
            if(j>1)
                check(vec,i,j-1,row,col);
            if(i+1<row)
                check(vec,i+1,j,row,col);
            if(j+1<col)
                check(vec,i,j+1,row,col);
        }
    }
};
*/
class Solution {
public:
    void solve(vector<vector<char>>& board){
        if(board.size() == 0 || board[0].size() == 0)return;
        vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board[0].size(); ++i){
            if(board[0][i] != 'X' && flag[0][i] == false)sub3(board, flag, 0, i);
            if(board[board.size()-1][i] != 'X' && flag[board.size()-1][i] == false)
                sub3(board, flag, board.size()-1, i);
        }
        for(int i = 1; i < board.size()-1; ++i){
            if(board[i][0] != 'X' && flag[i][0] == false)sub3(board, flag, i, 0);
            if(board[i][board[0].size()-1] != 'X' && flag[i][board[0].size()-1] == false)
                sub3(board, flag, i, board[0].size()-1);
        }
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(flag[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void sub3(vector<vector<char>> &board, vector<vector<bool>> &flag, int x, int y){
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        flag[x][y] = true;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i){
                switch(i){
                    case 0:
                        x = cur.first-1;y = cur.second;
                        break;
                    case 1:
                        x = cur.first+1;y = cur.second;
                        break;
                    case 2:
                        x = cur.first; y = cur.second-1;
                        break;
                    case 3:
                        x = cur.first; y = cur.second+1;
                        break;
                }
                if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size()){
                    if(flag[x][y] == false && board[x][y] != 'X'){
                        flag[x][y] = true;
                        q.push(make_pair(x,y));
                    }
                }
            }
        }
    }

    void solve1(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)return;
        vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                if(board[i][j] != 'X' && flag[i][j] == false){
                    bool ret = sub(board, flag, i, j);
                    if(ret == true){
                        sub2(board, i, j);
                    }
                }
            }
        }
    }

    bool sub(vector<vector<char>> &board, vector<vector<bool>> &flag, int x, int y){
        if(board[x][y] == 'X' || flag[x][y] == true)return true;
        if(x == 0 || x == board.size()-1)return false;
        if(y == 0 || y == board[0].size()-1)return false;
        bool ret = true;
        flag[x][y] = true;
        if(ret && sub(board, flag, x-1, y) == false)ret = false;
        if(ret && sub(board, flag, x+1, y) == false)ret = false;
        if(ret && sub(board, flag, x, y-1) == false)ret = false;
        if(ret && sub(board, flag, x, y+1) == false)ret = false;
        return ret;
    }

    void sub2(vector<vector<char>> &board, int x, int y){
        if(x < 0 || x > board.size()-1)return;
        if(y < 0 || y > board[0].size()-1)return;
        if(board[x][y] == 'X')return;
        board[x][y] = 'X';
        sub2(board, x-1, y);
        sub2(board, x, y-1);
        sub2(board, x+1, y);
        sub2(board, x, y+1);
    }
};
/*
第二次做：
跟第一次同样的问题，竟然是因为递归而RTE了。实在是憋屈啊。
艹，为啥人家的递归就没有问题呢。。。。。。。。。。。。。。
*/
class Solution {
private:
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (board[x][y] != 'O') return;
        //iterative
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        board[x][y] = '#';
        const int ix[] = {-1, 0, 1, 0}, iy[] = {0, 1, 0, -1};
        while (q.size()) {
            auto cur = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                x = cur.first + ix[i];
                y = cur.second + iy[i];
                if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'O') {
                    board[x][y] = '#';
                    q.push(make_pair(x, y));
                }
            }
        }

        //recursive
        /*
        if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size() || board[x][y] != 'O') return;
        board[x][y] = '#';
        const int ix[] = {-1, 0, 1, 0}, iy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            dfs(board, x+ix[i], y+iy[i]);
        }
        */
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        for (int i = 0; i < board.size(); ++i) {
            dfs(board, i, 0);
            dfs(board, i, board[0].size()-1);
        }
        for (int i = 0; i < board[0].size(); ++i) {
            dfs(board, 0, i);
            dfs(board, board.size()-1, i);
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
/*
 * old problem.
 */
class Solution {
private:
    void sub(vector<vector<char>> &board, int x, int y) {
        // recursion will overflow.
        const int ix[] = {-1, 1, 0, 0};
        const int iy[] = {0, 0, -1, 1};
        queue<pair<int,int>> q;
        q.push(make_pair(x, y));
        board[x][y] = 'T';
        while (q.size() > 0) {
            auto cur = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int xx = cur.first + ix[i];
                int yy = cur.second + iy[i];
                if (xx < 0 || yy < 0 || xx >= board.size() || yy >= board[0].size()) continue;
                if (board[xx][yy] != 'O') continue;
                board[xx][yy] = 'T';
                q.push(make_pair(xx, yy));
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.size() < 3 || board[0].size() < 3) return;

        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O') sub(board, i, 0);
            if (board[i][board[i].size()-1] == 'O') sub(board, i, board[i].size()-1);
        }
        for (int i = 1; i < board[0].size()-1; ++i) {
            if (board[0][i] == 'O') sub(board, 0, i);
            if (board[board.size()-1][i] == 'O') sub(board, board.size()-1, i);
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
