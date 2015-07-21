#include <stdio.h>
#include <stdlib.h>

/**
 * Problem: implement pow(x, n)
 * Solve: traverse every bit of n
 * Tips: notice that when n < 0 and n = MIN_INF
 */
double myPow(double x, int n) 
{
	double r = 1;
	int flag = 1;
	long t = n;
	if (t < 0) {
		t = -t;
		flag = 0;
	}
	while (t) {
		int bit = t & 0x1; 
		if (bit) {
			r *= x;	
		}
		x *= x;
		n >>= 1;
	}
	

	if (!flag) return 1/r;
	return r;
}

int main()
{
	int n;
	double x;
	while (~scanf("%lf %d", &x, &n)) {
		double r = myPow(x, n);
		printf("pow(%lf, %d) is %lf\n", x, n, r);
	}

	return 0;
}
