/**
 * Problem: Given a non-negative integer c, your task is
 *          to decide whether there're two integers a and
 *          b such that a2 + b2 = c.
 * Solve: straight-forward
 * Tips: no
 */
class Solution {
    public:
        bool judgeSquareSum(int c) {
            int q = sqrt(c);
            if (q*q == c) return true;

            for (int i = 1; i <= q; ++i) {
                int a = i * i;
                int b = c - a;
                if (a > b) break;

                int j = sqrt(b);
                if (j * j == b) return true;
            }

            return false;
        }

};
