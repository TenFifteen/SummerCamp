/**
 * Problem: reverse a string
 * Solve: just reverse
 * Tips: no
 */
class Solution {
    public:
        string reverseString(string s) {
            int len = s.size();
            int half = len / 2;
            for (int i = 0; i < half; ++i) {
                swap(s[i], s[len-1-i]);

            }

            return s;

        }

};
