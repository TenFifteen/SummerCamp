#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Problem: use the opreators except *, / and mod to divide two inegers
 * Solve: we can use the opreators: <<, + and -.
 *        each loop, we can multify the divisor use <<, then let the
 *        dividend minus the number we get before it is too large.
 *        then we go to another loop to double the temp.
 * Tips:  1. to avoid (temp<<1) < 0, we should use long, otherwise, we
 *		     will get a endless loop.
 *		  2. when dividend is MIN_INT, we should handle it carefully.
 *		     that is, MIN_INT/-1 = MAX_INT. but if we use long, MIN_INT/-1
 *		     = (long)MAX_INT+1 = (int)MIN_INT
 */
#define MAX_INT (-1 ^ (1 << 31))
#define MIN_INT (1 << 31)
int divide(int dividend, int divisor)
{
	if (divisor == 0) return MAX_INT;
	if (dividend == MIN_INT) {
		if (divisor == -1) return MAX_INT;
		else if (divisor == 1) return MIN_INT;
	}

	long m = dividend;
	long n = divisor;
	int sign = 1;
	if (m < 0) {sign  = -sign, m = -m;}
	if (n < 0) {sign = -sign, n = -n;}

	long result = 0;
	while (m >= n) {
		long temp = n, factor = 1;
		while (m >= (temp<<1)) {
			temp <<= 1;
			factor <<= 1;
		}
		result += factor;
		m -= temp;
	}

	return sign  == 1 ? result : -result;
}

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;

        int sign = 1;
        long long a = dividend, b = divisor;
        if (a < 0) { a = -a; sign = -sign;}
        if (b < 0) { b = -b; sign = -sign;}
        if (b == 1) return sign * a;

// must use long long in it, or it will overflow. it > INT_MAX, become INT_MIN
        long long it = b;
        long long ans = 0, fac = 1;
        while (it <= a) {
            it <<= 1;
            fac <<= 1;
        }

        it >>= 1; fac >>= 1;
        a -= it; ans += fac;
        while (a >= b) {
            while (a < it) {
                it >>= 1;
                fac >>= 1;
            }

            a -= it;
            ans += fac;
        }

// * is forbidden
        return sign * ans;
    }
};
int main()
{
	/*int n = 1000;
	  while (n--) {
	  int a = rand() % 1000000;
	  int b = rand() % 1000;
	  printf("--%d/%d=%d\n", a, b, a/b);
	  printf("**%d/%d=%d\n", a, b, divide(a, b));
	  printf("\n");
	  } */

	int a = -1010369383;
	int b = -2147483648;
	printf("**%d/%d=%d\n", a, b, divide(a, b));
	printf("%d\n", MAX_INT);
}

