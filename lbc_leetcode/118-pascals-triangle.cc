/*
题目大意：
给定一个整数n。求出pascal三角。

解题思路：
递推

遇到的问题：
一次通过。

再次阅读：
就是一道极其简单的题目，解法没啥问题。
还有一种思路，就是直接声明足够数量的数组，然后后面进行resize操作，设置为实际的数组大小。
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }
};
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> cur;
        if(numRows == 0)return ans;
        cur.push_back(1);
        ans.push_back(cur);
        for(int i = 1; i < numRows; ++i){
            vector<int> next;
            next.push_back(1);
            for(int j = 1; j < cur.size(); ++j){
                next.push_back(cur[j] + cur[j-1]);
            }
            next.push_back(1);
            ans.push_back(next);
            cur = next;
        }
        return ans;
    }
};
/*
第二次做：
简单题，不过还是有一个条件写错了。。。
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) return ans;
        
        ans.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; ++i) {
            vector<int> next;
            next.push_back(1);
            for (int j = 0; j < i-1; ++j) {
                next.push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            next.push_back(1);
            ans.push_back(next);
        }
        
        return ans;
    }
};