/**
 * Problem: Additive number is a string whose digits can form additive sequence.
 * Solve: dfs
 * Tips: the a and b should be long long, if the num long enough, then we should
 *       reconsider it.
 */
class Solution {
    public:
        bool isAdditiveNumber(string num) {
            if (num.size() < 3) return false;

            int n = num.size();
            bool ans = false;
            dfs(ans, num, 0, -1, -1, 0);

            return ans;
        }

        void dfs(bool &find, string &num, int pos, long long a, long long b, int cnt) {
            if (find) return;
            if (pos >= num.size()) {
                // cnt means the count of oprands
                if (a >= 0 && b >= 0 && cnt >= 3) find = true;
                return;
            }

            long long now = 0, i = pos;
            while (i < num.size() && !find) {
                now = now * 10 + (num[i]-'0');
                if (a < 0 || b < 0 || a + b == now) {
                    dfs(find, num, i+1, b, now, cnt+1);
                }

                if (num[pos] == '0') break;
                ++i;
            }
        }
};
