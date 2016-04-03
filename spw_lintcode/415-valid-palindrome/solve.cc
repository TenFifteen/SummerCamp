/**
 * Problem: Given a string, determine if it is a palindrome,
 *          considering only alphanumeric characters and ignoring cases.
 * Solve: two pointers.
 * Tips: upper character
 */
class Solution {
    public:
        bool isChar(char &c) {
            if (c >= 'a' && c <= 'z' ||  c >= '0' && c <= '9'){
                return true;
            } else if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
                return true;
            }

            return false;
        }

        /**
         * @param s A string
         * @return Whether the string is a valid palindrome
         */
        bool isPalindrome(string& s) {
            // Write your code here
            int n = s.size();

            int l = 0, r = n - 1;

            while (l < r) {
                while (l < r && !isChar(s[l])) ++l;
                while (l < r && !isChar(s[r])) --r;

                if (l < r && s[l] != s[r]) return false;
                ++l; --r;
            }

            return true;
        }
};
