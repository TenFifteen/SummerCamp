/*
题目大意：
给定一个k，返回第k行的pascal三角的值。要求空间复杂度为k

解题思路：
跟118题一样。

遇到的问题：
偷了个懒，直接拿118题改了改。

再次阅读：
这道题还是可以更加优化一下空间使用的：
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> A(rowIndex+1, 0);
        A[0] = 1;
        for(int i=1; i<rowIndex+1; i++)
            for(int j=i; j>=1; j--)
                A[j] += A[j-1];
        return A;
    }
};
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> cur;
        if(rowIndex == 0)return cur;
        cur.push_back(1);
        for(int i = 1; i < rowIndex; ++i){
            vector<int> next;
            next.push_back(1);
            for(int j = 1; j < cur.size(); ++j){
                next.push_back(cur[j] + cur[j-1]);
            }
            next.push_back(1);
            cur = next;
        }
        return cur;
    }
};
/*
第二次做：
嗯，看来还是我做题太不灵活了，既然从前往后不可以避免覆盖问题，为什么不反着来呢。
DISCUSS中就是这种思路。
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) return vector<int>();
        if (rowIndex < 2) return vector<int>(rowIndex+1, 1);
        
        vector<int> ans(2, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            vector<int> next(i+1, 1);
            for (int j = 1; j < i; ++j) {
                next[j] = ans[j-1] + ans[j];
            }
            ans.swap(next);
        }
        
        return ans;
    }
};