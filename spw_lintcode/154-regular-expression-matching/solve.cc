/**
 * Problem: '.' Matches any single character.
 *          '*' Matches zero or more of the preceding element.
 *          The matching should cover the entire input string (not partial).
 *          The function prototype should be:
 *          bool isMatch(const char *s, const char *p)
 * Solve: 1. iterator pointer on pattern string, and ++s every time.
 *           because we should judge if the *(p+1) then *p, that is c
 *           must not be zero.
 */
class Solution {
    public:
        /**
         * @param s: A string
         * @param p: A string includes "." and "*"
         * @return: A boolean
         */
        bool isMatch(const char *s, const char *p) {

            for (char c = *p; c; c = *p, ++s) {
                if (*(p+1) != '*') {
                    ++p;
                } else if (isMatch(s, p+2)) {// use p+2, because *(p+1) == '*', then p+2 is valid
                    return true;
                }

                // now c patter
                if (*s == 0 || c != '.' && c != *s) return false;
            }

            return *s == 0;
        }
};
