/**
 * Problem: You are given a string representing an attendance record
 *          for a student. The record only contains the following three characters:
 *          'A' : Absent.
 *          'L' : Late.
 *          'P' : Present.
 *          A student could be rewarded if his attendance record doesn't
 *          contain more than one 'A' (absent) or more than two continuous 'L' (late).
 *          You need to return whether the student could be rewarded according to his attendance record.
 * Solve:  just traversal and count
 * Tips: i > 2 and merge the special judgment
 */
class Solution {
    public:
        bool checkRecord(string s) {
            int n = s.size();

            bool hasA = false;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'A') {
                    if (hasA) return false;
                    hasA = true;
                } else if (s[i] == 'L') {
                    if (i >= 2 && s[i-1] == 'L' && s[i-2] == 'L')
                        return false;
                }
            }

            return true;
        }
};
