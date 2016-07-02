#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Problem: implement the lib function: strstr()
 * Solve: First, get the next array, then begin to find the position.
 * Tips: 1. when get the next array, we use two pointers to identify the 
 *          prefix and postfix
 *       2. compare p[k] and p[j] to get next[j+1]
 *       3. boundary condition: next[0] = -1, every time we slide patter string: 
 *          k -> next[k] -> ... -> -1, when k = -1, then we will slide the source 
 *          string(in the next loop)
 *          
 *          when we get -1? next[0], that is to say, s[i] != p[0].
 *          we use -1 to identify that we lose the match. then i++, j++. 
 *       4. the time to fill next[]: when k == -1 and p[j] == p[k]. 
 *          We only slide the pattern string the remaining time
 */
void get_next(char *p, int next[], int p_len)
{
	int k = -1;
	next[0] = -1;
	
	int j = 0;
	while (j < p_len) {
		// prefix: p[0...k], postfix: p[k-j...j]
		// compare p[k] and p[j] then we can fill next[j+1]
		if (k == -1 || p[j] == p[k]) {
			k++;
			j++;
			next[j] = k;
		} else {
			k = next[k];
		}
	}
}

int strStr(char* haystack, char* needle) 
{
	int p_len = strlen(needle);
	int *next = malloc(sizeof(int) * (p_len + 1));
	get_next(needle, next, p_len);

	int i = 0, j = 0;
	int s_len = strlen(haystack);

	while (i < s_len && j < p_len) {
		if (j == -1 || haystack[i] == needle[j]) {
			i++, j++;
		} else {
			j = next[j];
		}
	}

	if (j == p_len) {
		return i - j;
	} else {
		return -1;
	}
}

int main()
{
	char *s = "abcdef";
	char *p = "def";

	printf("the position of string '%s' in '%s' is %d\n", p, s, strStr(s, p));

	return 0;
}
