/*
题目大意：
给定一个数组，如果一个元素为0，则把该行该列的所有值都置为0。

解题思路：
可以用一个m+n空间的缓存记录那些行列有0，然后再将其都置为0；
也可以只记录第一行和第一列是否有0，其他的都记录在第一行和第一列中，
就可以实现常数空间了。

遇到的问题：
一次通过。

再次阅读：
虽然之前写的代码没有什么问题，但是有点啰嗦，看一下下面这个DISCUSS中的代码吧：
访问顺序非常重要。
void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)return;
        bool row = false, col = false;
        for(int i = 0; i < matrix.size(); ++i){
            if(matrix[i][0] == 0){
                col = true;
                break;
            }
        }
        for(int i = 0; i < matrix[0].size(); ++i){
            if(matrix[0][i] == 0){
                row = true;
                break;
            }
        }
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); ++i){
            if(matrix[i][0] == 0){
                fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }
        for(int i = 1; i < matrix[0].size(); ++i){
            if(matrix[0][i] == 0){
                for(int j = 1; j < matrix.size(); ++j){
                    matrix[j][i] = 0;
                }
            }
        }
        if(row){
            for(int i = 0; i < matrix[0].size(); ++i){
                matrix[0][i] = 0;
            }
        }
        if(col){
            for(int i = 0; i < matrix.size(); ++i){
                matrix[i][0] = 0;
            }
        }
    }
};
/*
第二次做：
还算是顺利吧，不过有一个起始条件把1写成0了，结果找了半天的bug。
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;

        int m = matrix.size(), n = matrix[0].size();

        //keep first row and col
        bool row = false, col = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                row = true;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                col = true;
                break;
            }
        }

        //get all zeros
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        //set all zeros
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        //set first row and col
        if (row) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        if (col) for (int i = 0; i < n; ++i) matrix[0][i] = 0;
    }
};
/*
 * tedious
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();
        bool row = false, col = false;
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                row = true;
                break;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                col = true;
                break;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row) for (int i = 0; i < n; ++i) matrix[0][i] = 0;
        if (col) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
    }
};
