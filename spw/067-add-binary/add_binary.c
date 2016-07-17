#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define max(a, b) ((a) > (b) ? (a) : (b))
char* addBinary(char* a, char* b) 
{
	int alen = strlen(a);
	int blen = strlen(b);

	int len = max(alen, blen);
	char *ans = malloc(sizeof(char) * (len + 1));
	char *r = malloc(sizeof(char) * (len + 1));
	
	char *ea = a + (alen - 1);
	char *eb = b + (blen - 1);
	char *s = ans + len;

	s[1] = '\0';
	int carry = 0;
	while (ea >= a && eb >= b) {
		int digit = carry + (*ea-'0') + (*eb-'0');
		*s = digit % 2 + '0';
		carry = digit / 2;

		s--, ea--, eb--;
	}
	while (ea >= a) {
		int digit = carry + (*ea-'0');
		*s = digit % 2 + '0';
		carry = digit / 2;

		s--, ea--;
	}
	while (eb >= b) {
		int digit = carry + (*eb-'0');
		*s = digit % 2 + '0';
		carry = digit / 2;

		s--, eb--;
	}

	if (carry) {
		*s = '1';
		return s;
	}
	++s;
	char *t = r;
	while (*s) {
		*t++ = *s++;
	}
	*t = '\0';
	free(ans);
	return r;
}

int main()
{
	char a[N];
	char b[N];
	while (~scanf("%s %s", a, b)) {
		char *r = addBinary(a, b);
		printf("The result of %s and %s is %s\n", a, b, r);
		free(r);
	}

	return 0;
}
