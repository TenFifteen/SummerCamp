/*
题目大意：
将一个矩阵旋转着输出。

解题思路：
直接模拟；

遇到的问题：
各种边界问题啊。
感觉这个题写的实在是不优雅。
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