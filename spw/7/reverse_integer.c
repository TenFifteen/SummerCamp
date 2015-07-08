#include <stdio.h>


/**
 * derive from 1, and multi the base each time 
 * notice : may be overflow
 */
int reverse(int x)
{
	if (x == 0) return 0;

	int r = 0;
	while (x) {
		if (r != r * 10 / 10) return 0;// overflow
		r = r * 10 + x % 10;
		x /= 10;
	}

	return r;
}

int main()
{
	int num;
	while (~scanf("%d", &num)) {
		printf("origin:%d\treverse:%d\n", num, reverse(num));
	}

	return 0;
}
