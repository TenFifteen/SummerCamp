/**
 * Problem: Compare two strings A and B, determine whether A contains all of the characters in B.
 *          The characters in string A and B are all Upper Case letters.
 * Solve: hash table
 * Tips: count not have
 */
class Solution {
    public:
        /**
         * @param A: A string includes Upper Case letters
         * @param B: A string includes Upper Case letter
         * @return:  if string A contains all of the characters in B return true
         *           else return false
         */
        bool compareStrings(string A, string B) {
            int table[26] = {0};
            for (int i = 0; i < 26; ++i) table[i] = 0;

            for (int i = 0; i < A.size(); ++i) {
                table[A[i]-'A']++;
            }

            for (int i = 0; i < B.size(); ++i) {
                if (--table[B[i]-'A'] < 0) return false;
            }

            return true;
        }
};

