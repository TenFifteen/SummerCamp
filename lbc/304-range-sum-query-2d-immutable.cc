/*
题目大意：
给定一个二维矩阵，不断的查询其中的子矩阵的总和。
而且矩阵是不变的。

解题思路：
将每个buf[i][j]表示从0，0到i，j这个子矩阵的大小。
然后根据传入的参数计算结果。

遇到的问题：
没有问题。
*/
class NumMatrix {
    vector<vector<int> > buf;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> tmp(matrix[i]);
            for (int j = 1; j < tmp.size(); ++j) {
                tmp[j] += tmp[j-1];
            }
            buf.push_back(tmp);
        }
        
        if (matrix.size() != 0) for (int i = 0; i < matrix[0].size(); ++i) {
            for (int j = 1; j < matrix.size(); ++j) {
                buf[j][i] += buf[j-1][i];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) return buf[row2][col2];
        if (row1 == 0) return buf[row2][col2] - buf[row2][col1-1];
        if (col1 == 0) return buf[row2][col2] - buf[row1-1][col2];
        return buf[row2][col2] + buf[row1-1][col1-1] - buf[row1-1][col2] - buf[row2][col1-1]; 
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);