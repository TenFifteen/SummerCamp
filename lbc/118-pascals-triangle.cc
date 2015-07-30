/*
题目大意：
给定一个整数n。求出pascal三角。

解题思路：
递推

遇到的问题：
一次通过。
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