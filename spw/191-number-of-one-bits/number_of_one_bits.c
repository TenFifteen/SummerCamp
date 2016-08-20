#include <stdio.h>
#include <stdlib.h>

/**
 * Problem: write a function to take an unsigned integer and return
 *          the numbers of '1' bits it has.
 * Solve: fetch every bit of int and count 1s of them.
 * Tips: no
 */
int hammingWeight(int n)
{
	int count = 0;
	while (n) {
		count += 0x1 & n;
		n >>= 1;
	}
	return count;
}

int hammingWeight1(int n)
{
	int count = 0;
	while (n) {
		n &= n-1;// delete the right most '1'
		++count;
	}
	return count;
}

int main()
{
	int n;
	while (~scanf("%d", &n)) {
		printf("The 1 bits of number %d is %d\n", n, hammingWeight(n));
	}

	return 0;
}

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            ++cnt;

            n = n & n-1;
        }

        return cnt;
    }
};
