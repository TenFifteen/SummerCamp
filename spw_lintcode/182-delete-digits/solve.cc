/**
 * Problem: Given string A representative a positive integer which has
 *          N digits, remove any k digits of the number, the remaining
 *          digits are arranged according to the original order to become
 *          a new positive integer.
 *          Find the smallest integer after remove k digits.
 *          N <= 240 and k <= N,
 * Solve: find the first peak and remove it one by one
 * Tips: see comments below.
 */
class Solution {
    public:
        /**
         *@param A: A positive integer which has N digits, A is a string.
         *@param k: Remove k digits.
         *@return: A string
         */
        string DeleteDigits(string A, int k) {
            int n = A.size();
            if (k == 0 || n == 0) return A;
            if (k == n) return "";


            while (k--) {
                int i = 0;
                while (i < n && A[i] == 'x') ++i;

                if (i < n) {
                    int prev = i++;
                    bool changed = false;
                    while (i < n) {
                        if (A[i] != 'x') {
                            if (A[prev] <= A[i]) {
                                prev = i;
                            } else {
                                A[prev] = 'x';
                                changed = true;
                                break;
                            }
                        }
                        ++i;
                    }
                    // if it is a no-decreasing sequence, then delete
                    // the final one.
                    if (!changed) A[prev] = 'x';
                }
            }

            string ans;

            int i = 0;
            // skip the precursor zeroes.
            while (i < n && (A[i] == 'x' || A[i] == '0')) ++i;

            while (i < n) {
                if (A[i] != 'x')
                    ans += A[i];
                ++i;
            }

            return ans;
        }
};

