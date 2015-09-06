#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isMatch1(char* s, char* p) 
{
	char now;
	int len = strlen(s);
	int n = strlen(p);

	int i, pos = 0;
	for (i = 0; i < len; ++i) {
		char c = p[pos];
		if (p[pos+1] != '*') {
			++pos;
		} else if (isMatch1(s, p+2)) {
			return 1;
		}

		if (s[i] == 0 || c != '.' && c != s[i]) return 0;
	}

}

/**
 * Problem: Implement regular expression matching with support for '.' and '*'
 * Solve: two string, traverse one and judge.
 * Tips: 1. when there has a * , we handle it seperately. 
 */
int isMatch(char* s, char* p)  
{
	char c; // used to keep the now pattern character, because we have ++p.
	for (c = *p; c != 0; ++s, c = *p) {
		if (*(p+1) != '*') {
			++p; // only place to move p
		} else if (isMatch(s, p+2)) {
			return 1; // omit 'c*'
		}

		if (*s == 0 || c != '.' && *s != c) return 0;
	}

	return *s == 0;
}
int main()
{
	char s[100], p[100];
	while (~scanf("%s %s", s, p)) {
		printf("isMatch(%s, %s) is %d\n", s, p, isMatch(s, p));
	}

	return 0;
}
