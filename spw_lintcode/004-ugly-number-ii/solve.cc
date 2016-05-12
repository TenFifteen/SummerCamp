/**
 * Problem: Ugly number is a number that only have factors 2, 3 and 5.
 *          Design an algorithm to find the nth ugly number. The first
 *          10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...
 * Solve: a vector and three pointer.
 * Tips: use the number before to generate a sequence.
 */
class Solution {
    public:
        /*
         ** @param n an integer
         ** @return the nth prime number as description.
         **/
        int nthUglyNumber(int n) {
            vector<int> ans(n);

            ans[0] = 1;
            int i2 = 0, i3 = 0, i5 = 0;
            int pos = 1;

            while (pos < n) {
                int now = min(min(ans[i2]*2, ans[i3]*3), ans[i5]*5);
                ans[pos++] = now;

                if (now % 2 == 0) i2++;
                if (now % 3 == 0) i3++;
                if (now % 5 == 0) i5++;
            }

            return ans[n-1];

        }

};
