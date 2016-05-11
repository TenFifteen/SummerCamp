/**
 * Problem: For a given source string and a target string, you should output the
 *          first index(from 0) of target string in source string.
 *          If target does not exist in source, just return -1.
 * Solve: kmp
 * Tips: 1. when get next, first lay pattern string ahead of source string by 1
 */
class Solution {
    public:
        /**
         * Returns a index to the first occurrence of target in source,
         * or -1  if target is not part of source.
         * @param source string to be scanned.
         * @param target string containing the sequence of characters to match.
         */
        int strStr(const char *source, const char *target) {
            if (target == NULL || source == NULL) return -1;

            int slen = strlen(source), tlen = strlen(target);
            if (tlen == 0) return 0;
            else if (slen == 0) return -1;

            int i = 0, j = 0;
            vector<int> next(tlen, 0);
            getNext(target, next);

            while (i < slen && j < tlen) {
                if (j == -1 || source[i] == target[j]) {
                    ++i, ++j;
                } else {
                    j = next[j];
                }
            }

            if (j == tlen) {
                return i - tlen;
            }
            return -1;
        }

        void getNext(const char *str, vector<int> &next) {
            int n = next.size();

            int i = 0, j = -1;

            next[0] = -1;
            while (i < n-1) {
                if (j == -1 || str[i] == str[j]) {
                    ++i, ++j;
                    next[i] = j;
                } else {
                    j = next[j];
                }
            }
        }
};

