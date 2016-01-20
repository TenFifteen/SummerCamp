#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Implement pow(x, n).
 * Solve: iterator every bit of n
 * Tips: 1. The factor must multiply itself instead of x.
 *       2. when n is negative.
 */
double myPow(double x, int n) {
    // Write your code here
    int sign = 0;
    if (n < 0) {
        sign = 1;
        n = -n;
    }

    int bit = 0x1;
    double factor = x;
    double ans = 1;
    // we can optimize here
    // int t = n;
    // while(t)
    for (int i = 0; i < 32; ++i) {
        if ((n >> i) & 0x1) {
            ans *= factor;
        }
        factor *= factor;
    }

    if (sign == 0)
        return ans;
    else
        return 1.000 / ans;
}
int main()
{

}
