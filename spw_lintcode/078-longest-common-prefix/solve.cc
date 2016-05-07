/**
 * Problem: Given k strings, find the longest common prefix (LCP).
 * Solve: use the first string as benchmark
 * Tips: when strs is empty
 */
class Solution {
    public:
        /**
         * @param strs: A list of strings
         * @return: The longest common prefix
         */
        string longestCommonPrefix(vector<string> &strs) {
            string ans;
            int index = 0;

            int n = strs.size();
            if (n == 0) return ans;
            while (index < strs[0].size()) {
                int i = 1;
                while (i < n) {
                    if (index >= strs[i].size() || strs[i][index] != strs[0][index]) break;
                    ++i;
                }

                if (i == n) {
                    ans += strs[0][index++];
                } else {
                    return ans;
                }
            }
        }
};
