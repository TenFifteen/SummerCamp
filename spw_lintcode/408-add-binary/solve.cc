/**
 * Problem: Given two binary strings, return their sum (also a binary string).
 * Solve: copy from leetcode
 * Tips: 1. use two pointers and decrease each when they are valid
 *       2. use a carry c to hold all sum each time.
 *       3. The condition can be simplify to let c be in.
 *       4. convert digit to char when add to the string.
 */
class Solution {
    public:
        /**
         ** @param a a number
         ** @param b a number
         ** @return the result
         **/
        string addBinary(string& a, string& b) {
            int i = a.size()-1, j = b.size()-1;

            int c = 0;
            string ans;
            while (i >= 0 || j >= 0 || c) {
                c += i >= 0 ? a[i--]-'0' : 0;
                c += j >= 0 ? b[j--]-'0' : 0;

                ans = (char)(c % 2 + '0') + ans;
                c /= 2;

            }

            return ans;

        }

};
