/*
题目大意：
给定一个二维矩阵，不断的查询其中的子矩阵的总和。
而且矩阵是不变的。

解题思路：
将每个buf[i][j]表示从0，0到i，j这个子矩阵的大小。
然后根据传入的参数计算结果。

遇到的问题：
没有问题。

再次阅读：
看了下DISCUSS，这种解法基本算是很不错的了。
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
/*
第二次做：
本来是一道很简单的饿题目。
结果首先是忘记了检查极端条件，主要是懒，倒不是忘了。
然后是计算矩形面积的时候，忘记了是二维了。
*/
class NumMatrix {
    vector<vector<long long>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();
        sum = vector<vector<long long>>(m+1, vector<long long>(n+1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = sum[i-1][j] + matrix[i-1][j-1];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] += sum[i][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
/*
 * ok
 */
class NumMatrix {
private:
    vector<vector<long long>> sum;

public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return; // corner case...
        sum = vector<vector<long long>>(matrix.size()+1, vector<long long>(matrix[0].size()+1));
        for (int i = 0; i < matrix.size(); ++i) {
            long long line = 0;
            for (int j = 0; j < matrix[0].size(); ++j) {
                line += matrix[i][j];
                sum[i+1][j+1] = sum[i][j+1] + line;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);


