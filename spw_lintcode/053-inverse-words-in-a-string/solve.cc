/**
 * Problem: Given an input string, reverse the string word by word.
 *          For example,
 *          Given s = "the sky is blue",
 *          return "blue is sky the".
 * Solve: trim the space and inverse twice.
 * Tips: while(str[--n]) --n; duplicates.
 */
class Solution {
    public:
        /**
         * @param s : A string
         * @return : A string
         */
        string reverseWords(string str) {
            string s = "";
            int i = 0, n = str.size();
            while (i < n && str[i] == ' ') ++i;
            while (str[--n] == ' ');
            while (i <= n) s += str[i++];

            reverse(s.begin(), s.end());

            int b = 0, e = 0;
            while (e <= s.size()) {
                if (s[e] == ' ' || e == s.size()) {
                    reverse(s.begin()+b, s.begin()+e);
                    b = e + 1;
                }
                ++e;
            }

            return s;
        }
};
