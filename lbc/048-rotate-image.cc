/*
题目大意：
给一个n*n的矩阵，将其向右翻转90°

解题思路：
找到每个需要翻转的元素，将其放到对应的位置。

遇到的问题：
一开始写成了向左翻转了。然后边界问题一开始也弄错了。

再次阅读：
感觉其实之前的方案挺好的。
另外一种方案就是按层来旋转。
DISCUSS里面有很多奇奇怪怪的解法，但是复杂度并没有改变，所以我觉得有以上
两种就足够了。
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() < 2)return;
        int n = matrix.size();
        for(int i = 0; i < n/2; ++i){
            for(int j = 0; j < (n+1)/2; ++j){
                swap(matrix[n-1-i][n-1-j], matrix[n-1-j][i]);
                swap(matrix[j][n-1-i], matrix[n-1-i][n-1-j]);
                swap(matrix[i][j], matrix[j][n-1-i]);
            }
        }
    }
};
/*
第二次做：
跟上次一样的解法。虽然那种按照层次结构来做的也挺好的，不过我已经先入为主了。
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < (n+1)/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};