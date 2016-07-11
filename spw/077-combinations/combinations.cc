#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &ans, vector<int> &one, int num, int n, int count, int k)
{
    if (count == k) {
        ans.push_back(one);
        return;
    }

    while (num <= n){
        one.push_back(num);

        dfs(ans, one, num+1, n, count+1, k);

        one.pop_back();
        ++num;
    }
}
/**
 * Problem: Given two integers n and k , return all possible combinations
 *           of k out of 1...n
 * Solve: DFS, draw a solution tree, then we can write the algorithm.
 * Tips: we need no flag vector
 */
vector<vector<int> > combine(int n, int k)
{
    vector<vector<int> > ans;
    if (n < k) return ans;

    vector<int> one;
    dfs(ans, one, 1, n, 0, k);
    return ans;
}

int main()
{
    int n, k;
    while (cin >> n >> k) {
        vector<vector<int> >  ans = combine(n, k);
        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < ans[i].size(); ++j) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> now;
        dfs(ans, now, 1, k, n);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &now, int pos, int k, int n) {
        if (now.size() >= k) {
            ans.push_back(now);
            return;
        }

// can iterator pos to save i
        for (int i = pos; i <= n; ++i) {
            now.push_back(i);
            dfs(ans, now, i+1, k, n);
            now.pop_back();
        }
    }
};
