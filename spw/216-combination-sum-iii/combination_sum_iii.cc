#include <iostream>
#include <vector>

/**
 * Problem: Use distinct 1~9 of count k, to obtain sum n.
 * Solve: dfs.
 * Tips: details.
 */
using namespace std;
class Solution {
    public:
        void dfs(vector<vector<int>> &ans, vector<int> &now, int up, int left, int k) {
            if (left == 0 && now.size() == k) {
                vector<int> tmp(now);
                reverse(tmp.begin(), tmp.end());
                ans.push_back(tmp);
                return;
            }

            if (now.size() < k && left > 0) {
                for (int i = min(left, up); i >= 1; --i) {
                    now.push_back(i);
                    dfs(ans, now, i-1, left-i, k);
                    now.pop_back();
                }
            }
        }

        vector<vector<int>> combinationSum3(int k, int n) {
            vector<vector<int>> ans;

            if (k > 9 || n > 45) return ans;
            vector<int> now;
            dfs(ans, now, 9, n, k);

            return ans;
        }
};

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if (k > 9 || n > (19 * k - k * k) / 2) return ans;

        vector<int> now;
        //for (int i = 1; i <= 9; ++i)
            dfs(ans, n, k, now, 1);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, int left, int cnt, vector<int>& now, int i) {
        if (cnt == 0 && left == 0) {
            ans.push_back(now);
            return;
        }
        if (cnt <= 0 || left <= 0 || i > 9) return;


        while (i < 10 && left-i >= 0) {
            now.push_back(i);
            dfs(ans, left-i, cnt-1, now, i+1);
            now.pop_back();

            ++i;
        }
    }
};
