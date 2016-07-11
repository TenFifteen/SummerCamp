#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) 
{
	if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
		char *p = malloc(sizeof(char) * 4);
		p[0] = '0';
		p[1] = '\0';
		return p;
	}

	int len1 = strlen(num1);
	int len2 = strlen(num2);
	char *end1 = num1 + len1 - 1;
	char *end2 = num2 + len2 - 1;

	while (*num1 == '\t' || *num1 == ' ') ++num1;
	while (*num2 == '\t' || *num2 == ' ') ++num2;

	int flag = 1;
	if (*num1 == '-') {
		flag = -flag;
		num1++;
	}
	if (*num2 == '-') {
		flag = -flag;
		num2++;
	}

	char *product = malloc(sizeof(char) * (len1 + len2 + 8));
	memset(product, '0', sizeof(product));
	char *endp = product + len1 + len2 + 8;
	*endp = '\0';
	while (*endp == '\0') --endp;

	char *d1, *d2;
	char *p;
	for (d1 = end1; d1 >= num1; --d1) {
		int carry = 0;
		int fac1 = *d1 - '0';
		if (fac1 == 0) continue;
		p = endp;
		for (d2 = end2; d2 >= num2; --d2, --p) {
			int fac2 = *d2 - '0';
			int origin = *p - '0';
			int digit = fac2 * fac1 + carry + origin;

			carry = digit / 10;
			*p = digit % 10 + '0';
		}
		*p = carry + '0';
		endp--;
	}

	if (flag == -1) {
		if (*p == '0') {
			*p = '-';
		}else {
			++p;
			*p = '-';
		}
	} else {
		if (*p == '0') {
			++p;
		}
	}

	return p;
}

int main()
{
	char fac1[10];
	char fac2[10];
	while (~scanf("%s %s", fac1, fac2)) {
		char *product = multiply(fac1, fac2);
		printf("The product of %s and %s is %s\n", fac1, fac2, product);
	}
	return 0;
}
