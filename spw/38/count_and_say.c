#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Problem: the next sequence derive from the previous sequence, we count and say
 * Solve: use two array to simulate
 * Tips: 1. can variable count > 9, that is count become a number occupy two digits
 *          we assume it will not here, but how can we prove it?
 *       2. how many space the nth sequence will occupy? we use 2*n and n = 18 will 
 *          be out of range. We use 100 in the end and we got accpetd.
 */
char* countAndSay(int n) 
{
	char *seq1 = malloc(sizeof(int) * (100 * n + 2));
	char *seq2 = malloc(sizeof(int) * (100 * n + 2));
	char *seq[2];
	seq[0] = seq1;
	seq[1] = seq2;

	int i, j;
	seq1[0] = '1';
	seq1[1] = '\0';
	for (i = 0; i < n-1; ++i) {
		char *pre = seq[i%2];
		char *now = seq[(i+1)%2];
		int len = strlen(pre);
		char digit;
		int count = 0, pos = 0;
		for (j = 0; j < len; ++j) {
			digit = pre[j];
			count = 1;
			while (j+1 < len && pre[j+1] == digit) {
				j++;
				count++;
			}
			now[pos++] = count + '0';
			now[pos++] = digit;
		}
		now[pos] = '\0';
	}

	if (n % 2 == 0) {
		free(seq1);
		return seq2;
	} else {
		free(seq2);
		return seq1;
	}
}

int main()
{
	int n;
	while (~scanf("%d\n", &n)) {
		char *n_cs = countAndSay(n);
		printf("%s\n", n_cs);
		free(n_cs);
	}
	return 0;
}
