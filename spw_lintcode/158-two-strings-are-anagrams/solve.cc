/**
 * Problem: Write a method anagram(s,t) to decide if two strings are anagrams or not.
 * Solve: use a vector with the length of 256
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param s: The first string
         * @param b: The second string
         * @return true or false
         */
        bool anagram(string s, string t) {
            int flag[256] = {0};

            int m = s.size(), n = t.size();
            if (m != n) return false;

            for (int i = 0; i < n; ++i) {
                flag[s[i]]++;
                flag[t[i]]--;
            }

            for (int i = 0; i < n; ++i) {
                if (flag[s[i]] != 0)
                    return false;
            }

            return true;
        }
};
