/**
 * Problem: Implement int sqrt(int x).
 *          Compute and return the square root of x.
 * Solve: divide and conquer
 * Tips: because of the result has been shift downward. Then
 *      we should use a extra place to hold the answer and update
 *      it instead of return l in the last which will miss the l,
 *      and break in the l+1 which (l+1)(l+1) > x
 */
#include <iostream>
#include <vector>

using namespace std;

int sqrt(int x) {
    long long l = 1, r = x;

    long long ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (mid * mid == x) {
            return mid;
        } else if (mid * mid < x) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return l;

}

int main()
{
    cout << sqrt(999999999) << endl;
    return 0;
}
