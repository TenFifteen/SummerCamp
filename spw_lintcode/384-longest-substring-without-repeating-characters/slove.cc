/**
 * Problem: Given a string, find the length of the longest
 *          substring without repeating characters.
 * Solve: use a vector as a table to remember the index of
 *        every character.
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param s: a string
         * @return: an integer
         */
        int lengthOfLongestSubstring(string s) {
            vector<int> table(256, -1);

            int n = s.size();
            int b = 0;
            int ans = 0;

            for (int i = 0; i < n; ++i) {
                if (table[s[i]] != -1) {
                    int e = table[s[i]];
                    // pass the e in the end
                    while (b <= e) table[s[b++]] = -1;
                }

                table[s[i]] = i;
                ans = max(ans, i-b+1);
            }

            return ans;
        }
};
