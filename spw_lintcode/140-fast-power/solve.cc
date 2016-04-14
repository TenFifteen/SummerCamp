/**
 * Problem: Calculate the an % b where a, b and n are all 32bit integers.
 * Solve: (a * b) % p == ((a%p) * (b%p)) % p
 * Tips: see comments below.
 */
class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // bottom.
        if (n == 0) return 1 % b;

        // can save some time
        //if (n == 1) return a % b;

        // instead of int, who will probably overflow
        long long half = fastPower(a, b, n/2);

        long long ans = half * half % b;

        if (n % 2 == 1) {
            ans = ans * (a % b) % b;
        }

        return ans;
    }
};
