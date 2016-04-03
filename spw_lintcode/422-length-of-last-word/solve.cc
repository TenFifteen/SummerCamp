/**
 * Problem: Given a string s consists of upper/lower-case
 *          alphabets and empty space characters ' ', return
 *          the length of last word in the string.
 * Solve: traversal from the end.
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param s A string
         * @return the length of last word
         */
        int lengthOfLastWord(string& s) {
            // Write your code here
            int n = s.size();

            int i = n-1;
            while (i >= 0 && s[i] == ' ') --i;

            int e = i;
            while (i >= 0 && s[i] != ' ') --i;

            return e - i;
        }
};
