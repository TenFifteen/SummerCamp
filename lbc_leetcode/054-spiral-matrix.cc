/*
题目大意：
将一个矩阵旋转着输出。

解题思路：
直接模拟；

遇到的问题：
各种边界问题啊。
感觉这个题写的实在是不优雅。

再次阅读：
看了一下之前写的代码，实在是有点长，不知道当时怎么就写的这么长了呢。
感觉思路并没有什么问题，就是代码难看。
找了一下DISCUSS中的代码，下面这个java的代码就稍微简洁一些了：
public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {

        List<Integer> res = new ArrayList<Integer>();

        if (matrix.length == 0) {
            return res;
        }

        int rowBegin = 0;
        int rowEnd = matrix.length-1;
        int colBegin = 0;
        int colEnd = matrix[0].length - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            // Traverse Right
            for (int j = colBegin; j <= colEnd; j ++) {
                res.add(matrix[rowBegin][j]);
            }
            rowBegin++;

            // Traverse Down
            for (int j = rowBegin; j <= rowEnd; j ++) {
                res.add(matrix[j][colEnd]);
            }
            colEnd--;

            if (rowBegin <= rowEnd) {
                // Traverse Left
                for (int j = colEnd; j >= colBegin; j --) {
                    res.add(matrix[rowEnd][j]);
                }
            }
            rowEnd--;

            if (colBegin <= colEnd) {
                // Traver Up
                for (int j = rowEnd; j >= rowBegin; j --) {
                    res.add(matrix[j][colBegin]);
                }
            }
            colBegin ++;
        }

        return res;
    }
}
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0 || matrix[0].size() == 0)return ans;
        int top = 0, bottom = matrix.size(),left = 0, right = matrix[0].size();
        int direction = 1;
        int x = 0, y = 0;
        for(int i = 0; i < matrix.size()*matrix[0].size(); ++i){
            ans.push_back(matrix[x][y]);
            switch(direction){
                case 1://left to right
                    if(y == right-1){
                        top++;
                        direction = 2;
                        x++;
                        continue;
                    }else{
                        y++;
                    }
                    if(y == right-1){
                        top++;
                        direction = 2;
                    }
                    break;
                case 2://top to bottom
                    if(x == bottom-1){
                        right--;
                        direction = 3;
                        y--;
                        continue;
                    }else{
                        x++;
                    }
                    if(x == bottom-1){
                        right--;
                        direction = 3;
                    }
                    break;
                case 3://right to left
                    if(y == left){
                        bottom--;
                        direction = 4;
                        x--;
                        continue;
                    }else{
                        y--;
                    }
                    if(y == left){
                        bottom--;
                        direction = 4;
                    }
                    break;
                case 4://bottom to top
                    if(x == top){
                        left++;
                        direction = 1;
                        x++;
                        continue;
                    }else{
                        x--;
                    }
                    if(x == top){
                        left++;
                        direction = 1;
                    }
                    break;
                default:
                    break;
            }
        }
        return ans;
    }
};
/*
第二次做：
这次写的代码还比较简洁，但是一开始没有考虑到for循环前面的那个if条件。
不过这次代码已经接近DISCUSS中的代码了。
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;

        int i = 0, j = 0, m = matrix.size(), n = matrix[0].size();
        while (i < m && j < n) {
            for (int k = j; k < n; ++k) {
                ans.push_back(matrix[i][k]);
            }
            i++;
            if (j < n) for (int k = i; k < m; ++k) {
                ans.push_back(matrix[k][n-1]);
            }
            n--;
            if (i < m) for (int k = n-1; k >= j; --k) {
                ans.push_back(matrix[m-1][k]);
            }
            m--;
            if (i < m && j < n) for (int k = m-1; k >= i; --k) {
                ans.push_back(matrix[k][j]);
            }
            j++;
        }

        return ans;
    }
};
/*
 * 还好
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;
        int left = 0, right = matrix[0].size()-1, top = 0, bot = matrix.size()-1;
        while (left <= right && top <= bot) {
            for (int i = left; i <= right; ++i) ans.push_back(matrix[top][i]);
            top++;
            if(left <= right) for (int i = top; i <= bot; ++i) ans.push_back(matrix[i][right]);
            right--;
            if (top <= bot) for (int i = right; i >= left; --i) ans.push_back(matrix[bot][i]);
            bot--;
            if (left <= right) for (int i = bot; i >= top; --i) ans.push_back(matrix[i][left]);
            left++;
        }
        return ans;
    }
};
