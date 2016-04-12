/**
 * Problem: Implement an algorithm to determine if a string has all unique characters.
 * Solve: table
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param str: a string
         * @return: a boolean
         */
        bool isUnique(string &str) {
            bool flag[256] = { false};

            for (int i = 0; i < str.size(); ++i) {
                if (flag[str[i]]) return false;
                flag[str[i]] = true;
            }

            return true;
        }
};
