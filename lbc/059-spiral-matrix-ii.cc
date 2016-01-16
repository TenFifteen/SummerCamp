/*
题目大意：
与54题类似，不过这次是填充数字，而不是访问数字。

解题思路：
与54题一样。

遇到的问题：
虽然之前的实现比较丑陋，还是直接拿过来了。

再次阅读：
我说怎么代码这么丑呢，原来是直接从上一个题目中拿过来的代码啊。
不过我现在已经知道怎么简化这个代码了：
class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > ret( n, vector<int>(n) );
            int k = 1, i = 0;
            while( k <= n * n )
            {
                int j = i;
                    // four steps
                while( j < n - i )             // 1. horizonal, left to right
                    ret[i][j++] = k++;
                j = i + 1;
                while( j < n - i )             // 2. vertical, top to bottom
                    ret[j++][n-i-1] = k++;
                j = n - i - 2;
                while( j > i )                  // 3. horizonal, right to left 
                    ret[n-i-1][j--] = k++;
                j = n - i - 1;
                while( j > i )                  // 4. vertical, bottom to  top 
                    ret[j--][i] = k++;
                i++;      // next loop
            }
            return ret;
        }
    };
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> tmp(n);
        vector<vector<int>> ans(n, tmp);
        if(n == 0)return ans;
        int top = 0, bottom = n,left = 0, right = n;
        int direction = 1;
        int x = 0, y = 0;
        for(int i = 0; i < n*n; ++i){
            ans[x][y] = i+1;
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