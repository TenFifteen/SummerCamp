/*
题目大意：
一个二维的01矩阵。求出其中全部都是1组成的子矩形的面积的最大值。

解题思路：
将二维的矩阵处理成一维的数组，然后根据84题的思路进行求解。
时间复杂度：n*n 空间复杂度：n*n

遇到的问题：
一开始没有思路，在查找解决方法的时候，突然想到，既然这个题目跟上一个题目类似，
应该是可以用类似的方法解的。
竟然一次性通过，感觉不错。

再次阅读：
这次竟然没有自己想出来。看了之前的解法才知道怎么弄的。
感觉还是挺厉害的。
看了一下DISCUSS中的讨论，最高的是一种DP的思路。但是没太看懂。
我觉得这种思路已经很不错了。所以先用这一种思路吧。
另外就是空间可以压缩到n。
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)return 0;
        vector<int> tmp(matrix[0].size()+1, 0);
        vector<vector<int>> hist(matrix.size(), tmp);
        for(int i = 0; i < matrix[0].size(); ++i){
            hist[0][i] = matrix[0][i] == '1' ? 1 : 0;
        }
        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                hist[i][j] = matrix[i][j] == '0' ? 0 : hist[i-1][j] + 1;
            }
        }
        int ret = 0;
        for(int i = 0; i < matrix.size(); ++i){
            int cur = sub(hist[i]);
            if(cur > ret){
                ret = cur;
            }
        }
        return ret;
    }
    
    int sub(vector<int> &hist){
        stack<int> sta;
        int index = 0;
        int ret = 0;
        while(index < hist.size()){
            if(sta.empty() || hist[sta.top()] <= hist[index]){
                sta.push(index++);
            }else{
                int cur = sta.top();
                sta.pop();
                int tmp = 0;
                if(sta.empty()){
                    tmp = hist[cur] * index;
                }else{
                    tmp = (index - sta.top() - 1) * hist[cur];
                }
                if(tmp > ret){
                    ret = tmp;
                }
            }
        }
        return ret;
    }
};