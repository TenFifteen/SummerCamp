/**
 * Problem: Given two strings s1 and s2, write a function to return true if
 *          s2 contains the permutation of s1. In other words, one of the
 *          first string's permutations is the substring of the second string.
 * Solve: dict + slide window
 * Tips: note that the character as the index.
 */
class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            int dict[128] = {0};
            for (char &c : s1)
                dict[c]++;

            int l1 = s1.size(), l2 = s2.size();
            if (l1 > l2) return false;

            int low = 0;
            for(int i = 0; i < l1; ++i) {
                if (--dict[s2[i]] < 0)
                    --low;
            }
            if (low == 0) return true;

            for (int i = l1; i < l2; ++i) {
                if (dict[s2[i-l1]]++ < 0) ++low;
                // character as the index
                if (--dict[s2[i]] < 0) --low;

                if (low == 0) return true;
            }

            return false;
        }
};
