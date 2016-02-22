/*
题目大意：
给定一个n，和k。
求出1-n数字的所有的k个数字的组合。

解题思路：
回溯。

遇到的问题：
无。

再次阅读：
没有问题。代码也还好。
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        sub(ans, cur, n, 1, k);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<int> &cur, int n, int i, int k){
        if(k == 0){
            ans.push_back(cur);
            return;
        }
        if(n-i+1 < k)return;
        cur.push_back(i);
        sub(ans, cur, n , i+1, k-1);
        cur.pop_back();
        sub(ans, cur, n, i+1, k);
    }
};