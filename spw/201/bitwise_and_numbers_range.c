#include <stdio.h>

/**
 * Problem:	Given an range [m, n] where  0 <= m <= n <= 2147483647, return the bitwise
 *          AND of all numbers in the range, inclusive.
 * Solve: in the base of m, traverse every bit, determin if cut this 1 or not.
 * Tips: if (before == m) represent the last bits are all zeroes.
 */
int rangeBitwiseAnd(int m, int n) {
	int i = 0;
	int now = 1;
	int before = 0;
	int range = n-m;

	int result = m;
	for (i = 0; i < 32; ++i) {
		if ((now & result) != 0) {
			int diff = now - before;
			if (range >= diff) result ^= now;
		}

		before += now & m;
		now <<= 1;
		if (before == m) break;
	}

	return result;
}
// copied from disscuss board, also 44ms
// Consider the bits from low to high. if n > m, the lowest bit will be 0, 
// and then we could transfer the problem to sub-problem: rangeBitwiseAnd(m>>1, n>>1).
int rangeBitwiseAnd(int m, int n) {
	    return (n > m) ? (rangeBitwiseAnd(m>>1, n>>1) << 1) : m;
}

int main()
{
	int m, n;
	while (~scanf("%d %d", &m, &n)) {
		printf("The range [%d, %d] bitwise AND is %d\n", m, n, rangeBitwiseAnd(m, n));
	}

	return 0;
}
