/**
 * Problem: Validate if a given string is numeric.
 * Solve: Assume that we have the most complex number, and handle every
 *       segment one by one, to see if the cursor will arrive the end.
 * Tips: must have a digit instead of a dot
 *       can't have two dot
 */
class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // Write your code here
        int n = s.size();
        int i = 0;

        // handle the preceding blank
        while (i < n && s[i] == ' ') ++i;

        // hand the sign
        if ( (s[i] == '+' || s[i] == '-')) {
            ++i;
        }

        // handle the digit and dot
        int dot = false;
        bool d = false;
        while (i < n && (s[i] == '.' || s[i] >= '0' && s[i] <= '9')) {
            if (dot && s[i] == '.') return false;

            if (s[i] == '.') dot = true;
            else d = true;
            ++i;
        }

        // handle e : base on that it have digits before
        if (d && s[i] == 'e') {
            ++i;
            if ( (s[i] == '+' || s[i] == '-')) {
                ++i;
            }

            while (i < n && s[i] >= '0' && s[i] <= '9') {
                ++i;
            }
        }

        // handle the tail blank
        while (i < n && s[i] == ' ') ++i;

        return i == n && d;
    }
};
