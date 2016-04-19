/**
 * Problem: You are climbing a stair case. It takes
 *          n steps to reach to the top.
 *          Each time you can either climb 1 or 2 steps.
 *          In how many distinct ways can you climb to the top?
 * Solve: fabnacii
 * Tips: n == 0, return 1
 */
class Solution {
    public:
        /**
         ** @param n: An integer
         ** @return: An integer
         **/
        int climbStairs(int n) {
            int l = 1, r = 1;

            for (int i = 2; i <= n; ++i) {
                int now = l + r;
                l = r;
                r = now;

            }

            return r;

        }

};
