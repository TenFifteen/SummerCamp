/*
题目大意：
用k个1-9的数字组合其和来组成n，不可以重复。

解题思路：
搜索

遇到的问题：
一开始以为是可以重复的。

再次阅读：
感觉这样做基本没啥问题了。
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> now;
        sub(k, n, 1, ans, now);
        return ans;
    }

    void sub(int k, int n, int cur, vector<vector<int>> &ans, vector<int> &now){
        if(n == 0){
            if(k == 0)ans.push_back(now);
            return;
        }
        if(k*cur > n || k*9 < n || k <= 0)return;
        for(int i = cur; i <= 9; ++i){
            now.push_back(i);
            sub(k-1, n-i, i+1, ans, now);
            now.pop_back();
        }
    }
};
/*
第二次做：
没有太大问题，就是一开始把k的含义看错了。
面试的时候一定要申清楚题目再做。
*/
class Solution {
private:
    void dfs(vector<vector<int>> &ans, vector<int> &now, int index, int k, int sum, int n) {
        if (sum == n && now.size() == k) {
            ans.push_back(now);
            return;
        }
        if (sum > n || index > 9 || now.size() > k) return;

        for (int i = index; i <= 9; ++i) {
            now.push_back(i);
            dfs(ans, now, i+1, k, sum+i, n);
            now.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> now;
        dfs(ans, now, 1, k, 0, n);
        return ans;
    }
};
/*
 * ok
 */
class Solution {
private:
    void dfs(vector<vector<int>> &ans, vector<int> &now, int k, int cur, int n) {
        if (n < 0) return;
        if (n == 0) {
            if (k == 0) ans.push_back(now);
            return;
        }
        if (k <= 0) return;
        for (int i = cur; i <= 9; ++i) {
            now.push_back(i);
            dfs(ans, now, k-1, i+1, n - i);
            now.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> now;
        dfs(ans, now, k, 1, n);
        return ans;
    }
};
