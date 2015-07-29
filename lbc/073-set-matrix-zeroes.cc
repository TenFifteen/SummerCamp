/*
题目大意：
给定一个数组，如果一个元素为0，则把该行该列的所有值都置为0。

解题思路：
可以用一个m+n空间的缓存记录那些行列有0，然后再将其都置为0；
也可以只记录第一行和第一列是否有0，其他的都记录在第一行和第一列中，
就可以实现常数空间了。

遇到的问题：
一次通过。
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