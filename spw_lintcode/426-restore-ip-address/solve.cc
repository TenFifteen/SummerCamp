/**
 * Problem: Given a string containing only digits, restore it
 *          by returning all possible valid IP address combinations.
 * Solve: back trace
 * Tips: see comments below
 */
class Solution {
public:
    void dfs(vector<string> &ans, string &s, int pos, string prefix, int cnt) {
        // use 'cnt' as the count of decimal numbers instead of count of dot
        if(cnt == 4 && pos == s.size()) {
            ans.push_back(prefix);
            return;
        }

        if (cnt >= 4) return;

        int n = s.size();
        int now = 0;
        for (int i = pos; i < n; ++i) {
            // if have prefix 0, then omit
            if (i > pos && s[pos] == '0') return;

            now = now * 10 + (s[i] - '0');
            string ss;
            if (now <= 255) {
                if (cnt == 0) ss = to_string(now);
                else ss = prefix + "." + to_string(now);
                dfs(ans, s, i+1, ss, cnt+1);
            } else {
                return;
            }
        }
    }
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<string> ans;
        dfs(ans, s, 0, "", 0);

        return ans;
    }
};
