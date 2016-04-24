/**
 * Problem: Given n unique integers, number k (1<=k<=n) and target.
 *          Find all possible k integers where their sum is target.
 * Solve: dfs
 * Tips: what is the time complexity. O(n!) ?
 */
class Solution {
    public:
        /**
         * @param A: an integer array.
         * @param k: a positive integer (k <= length(A))
         * @param target: a integer
         * @return a list of lists of integer
         */
        vector<vector<int> > kSumII(vector<int> A, int k, int target) {
            int n = A.size();
            sort(A.begin(), A.end());

            vector<int> prev;
            vector<vector<int>> ans;
            dfs(ans, A, prev, target, 0, k);

            return ans;
        }

        void dfs(vector<vector<int>> &ans, vector<int> &A, vector<int> &prev, int left, int pos, int k) {
            if (left <= 0 || prev.size() >= k) {
                if (prev.size() == k && left == 0)
                    ans.push_back(prev);
                return;
            }

            int n = A.size();
            for (int i = pos; i < n && A[i] <= left; ++i) {
                prev.push_back(A[i]);
                dfs(ans, A, prev, left-A[i], i+1, k);
                prev.pop_back();
            }
        }
};

