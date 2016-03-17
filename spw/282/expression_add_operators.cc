/**
 * Problem: Given a string that contains only digits 0-9 and a
 *          target value, return all possibilities to add binary
 *          operators (not unary) +, -, or * between the digits
 *          so they evaluate to the target value.
 * Solve: dfs (in every node, we select each edge by scale the count
 *        of digits, then the operators)
 * Tips: 1. How get the current value, by the last whole expression
 *          value and the last number value? Hold the last whole
 *          expression value and last continuous multiplications.
 *          Note that, in this case, we convert '-' to '+' by give
 *          a sign to the integer.
 *       2. Use long to hold the result.
 */
class Solution {
    private:
        void dfs(vector<string> &ans, string path, string &num, int pos, int target, long last, long eval) {
            if (pos == num.size() && eval == target) {
                ans.push_back(path);
                return;
            }

            for (int i = pos; i < num.size(); ++i) {
                if (i != pos && num[pos] == '0') break;

                string ss = num.substr(pos, i-pos+1);
                long now = stol(ss);

                if (pos == 0) {
                    dfs(ans, ss, num, i+1, target, now, now);

                } else {
                    dfs(ans, path+'+'+ss, num, i+1, target, now, eval+now);
                    dfs(ans, path+'-'+ss, num, i+1, target, -now, eval-now);
                    dfs(ans, path+'*'+ss, num, i+1, target, last*now, eval+(now-1)*last);

                }

            }

        }
    public:
        vector<string> addOperators(string num, int target) {
            vector<string> ans;
            if (num.size() == 0) return ans;

            dfs(ans, "", num, 0, target, 0, 0);
            return ans;

        }

};
