#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

/**
 * Problem: Length of Last Word
 * Solve: use a variable to count, update when we encounter blank character
 * Tips: if it is not from beginning, the last word should not be blank string
 *       then I use another variable to save the previous nonzero count.
 */
int lengthOfLastWord(char* s)  
{
	int pre = 0, count = 0;
	while (*s) {
		if (*s == ' ' || *s == '\t') {
			if (count != 0)
				pre = count;
			count = 0;
		} else {
			++count;
		}   
		++s;
	}   
	return count == 0 ? pre : count;
}
int main()
{
	char str[N];
	while (fgets(str, N, stdin)) {
		int len = lengthOfLastWord(str);
		printf("The length last word of '%s' is %d\n", str, len);
	}

	return 0;
}

