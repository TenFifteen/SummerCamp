/**
 * Problem: Given a string S, find the longest palindromic substring in
 *          S. You may assume that the maximum length of S is 1000, and
 *          there exists one unique longest palindromic substring.
 * Solve: use every character as the middle of the palindromic substring
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param s input string
         * @return the longest palindromic substring
         */
        string longestPalindrome(string& s) {
            // Write your code here
            int n = s.size();

            int len = 1;
            int start = 0;
            for (int i = 0; i < n; ++i) {
                int j = 1;
                while (i+j < n && i-j >= 0 && s[i-j] == s[i+j]) ++j;
                if (2*j-1 > len) {
                    len = 2*j-1;
                    start = i - j + 1;
                }


                j = 0;
                while (i-j >= 0 && i+j+1 < n && s[i-j] == s[i+j+1]) ++j;
                if (j*2 > len) {
                    len = 2 * j;
                    start = i - j + 1;
                }
            }

            return s.substr(start, len);
        }
};

string longestPalindrome(string s) {
    int n = s.size();

    int len = 1;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (n - i <= len/2) break;

        int e = i, b = i;
        // skip the duplicates then we need not handle the symcenter as i or i and i+1
        while (e+1 < n && s[e+1] == s[e]) ++e;

        // update the index
        i = e;

        while (b > 0 && e < n-1 && s[b-1] == s[e+1]) --b, ++e;

        if (e-b+1 > len) {
            len = e - b + 1;
            start = b;
        }
    }

    return s.substr(start, len);
}
