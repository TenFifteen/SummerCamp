#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Problem: Write the code that will take a string and make its zigzag conversion
 *          given number of rows.
 * Solve: focus on the steps and its variation.
 * Tips: in the middle of the row, there are only two kind of steps and change alternately. 
 */
char* convert(char* s, int nRows) {
	if (nRows <= 1) return s;

	int n = strlen(s);
	char *result = malloc(sizeof(char) * (n+1));

	int i, j, pos = 0;
	int step = 2 * nRows - 2;
	int flag = 0;
	for (i = 0; i < nRows; ++i) {
		if (i == 0 || i == nRows-1) {
			for (j = i; j < n; j += step) {
				result[pos++] = s[j];
			}
		} else {
			int right_step = 2 * i;	
			int left_step = step - right_step; 
			j = i;
			flag = 0;
			while (j < n) {
				result[pos++] = s[j];
				
				j += flag ? right_step : left_step;
				flag = !flag;
			}
		}
	}

	result[pos] = '\0';

	return result;
}
int main()
{
	char s[100];
	while (~scanf("%s", s)) {
		printf("The zigzag of string %s is %s\n", s, convert(s, 3));
	}

	return 0;
}
