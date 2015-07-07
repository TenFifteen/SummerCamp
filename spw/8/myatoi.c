#include <stdio.h>
#include <string.h>


/**
 * ignore the first continus blank character
 * more than one sign are not allowed
 * return immediately when encounter the invalid chatacter
 * notice the int range
 */
int myAtoi(char *str)
{
	long MAX_INT = 2147483647;
	long MIN_INT = -2147483648;

	if (str == NULL) return 0;
	int s = 0;
	while (str[s] == ' ' || str[s] == '\t') ++s;

	//notice sign 
	int flag = 1;
	if (str[s] == '-') {
		flag = -1;	
		++s;
	} else if(str[s] == '+') {
		flag = 1;
		++s;
	}

	long r = 0;
	while (str[s]) {
		long b = str[s] - '0';
		// notice the invalid character
		if (b < 0 || b > 9) return flag*r;

		r = r * 10 + b;

		// notice that int range
		if (r*flag >= MAX_INT) return MAX_INT;
		if (r*flag <= MIN_INT) return MIN_INT;
		++s;
	}

	return r * flag;
}


long main()
{
	char str[1000];
	while (~scanf("%s", str)) {
		printf("the num is %d\n", myAtoi(str));
		printf("the real num is %d\n", atoi(str));
	}

	return 0;
}
