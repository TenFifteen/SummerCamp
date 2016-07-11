#include <stdio.h>

int mySqrt1(int x) {
	int left = 0, right = x;
	while (left <= right) {
		int mid = (left + right) / 2;
		int result = mid * mid;
		if (result == x) return mid;

		if (result > x || result < 0) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return right;
}

/**
 * Problem: Implement int sqrt(int x).
 * Solve: binary search in rang [1, x]
 * Tips: mid*mid will probably be out of range of int, then
 *       we use division instead of multiplication.
 */
int mySqrt(int x) {
	if (x == 0) return 0;
	int left = 1, right = x;
	while (left <= right) {
		int mid = (left + right) / 2;

		int factor = x / mid;
		if (factor == mid) return mid;

		if (factor < mid) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	// when step out of the loop, left > right
	// and we need to return the smaller one
	return right;
}
int main()
{
	int n;
	while (~scanf("%d", &n)) {
		int x = mySqrt(n);
		printf("the square root of %d is %d\n", n, x);
	}

	return 0;
}

class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x;
        while (left <= right) {
            long long mid = left + (right - left) / 2;

            long long now = mid * mid;
            if (now == x) return mid;
            else if (now > x) right = mid - 1;
            else left = mid + 1;
        }

        return right;
    }
};
