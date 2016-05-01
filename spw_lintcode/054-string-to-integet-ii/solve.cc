/**
 * Problem: Implement function atoi to convert a string to an integer.
 *          If no valid conversion could be performed, a zero value is returned.
 *          If the correct value is out of the range of representable
 *          values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 * Solve: handle the space, sign and overflow.
 * Tips: ++i
 */
class Solution {
    public:
        /**
         * @param str: A string
         * @return An integer
         */
        int atoi(string str) {
            bool sign = true;

            int i = 0, n = str.size();
            while (i < n && str[i] == ' ') ++i;

            if (str[i] == '+') ++i;
            else if (str[i] == '-') {
                sign = false;
                ++i;
            }

            int ans = 0;
            while (i < n && (str[i] >= '0' && str[i] <= '9')) {
                int tmp = ans * 10 + (str[i] - '0');
                if (tmp / 10 != ans) return sign ? INT_MAX : INT_MIN;

                ans = tmp;
                ++i;
            }

            return sign ? ans : -ans;
        }
};
