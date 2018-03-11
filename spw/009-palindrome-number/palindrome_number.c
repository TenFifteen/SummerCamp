#include <stdio.h>

/**
 * fetch the first and last digit each time and compare them
 */
int isPalindrome(int x)
{
	if (x < 0) return 0;
	if (x / 10 == 0) return 1;

	int fac = 1, temp = x;
	while(temp / 10) {
		fac *= 10;
		temp /= 10;
	}

	while (fac) {
		int a = x % 10;
		int b = x / fac % 10;
		if (a != b) return 0;

		x /= 10;
		fac /= 100;
	}

	return 1;
}

/**
 * how to handle 10021 
 */
int is_palindrome(int x)
{
	if (x < 0) return 0;
	if (x / 10 == 0) return 1;

	int a = x % 10;
	int fac = 1, temp = x;
	while(temp / 10) {
		fac *= 10;
		temp /= 10;
	}
	int b = x / fac;

	return a == b && is_palindrome(x % fac / 10);
}

int main()
{
	int n;
	while (~scanf("%d", &n)) {
		int flag = is_palindrome(n);
		if (flag) printf("%d is palindrome.\n", n);
		else printf("%d is not palindrome.\n", n);
	}

	return 0;
}
