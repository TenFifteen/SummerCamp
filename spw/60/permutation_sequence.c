#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20
int fac[N];
int used[N];
int count = 0;
int find = 0;

/**
 * Problem: The set [1,2,3,…,n] contains a total of n! unique permutations.
 *          Given n and k, return the kth permutation sequence.
 * Solve: we use two ways: dfs and mathematical method
 * Tips: dfs: after invoing the dfs, if we find the right answer, we should
 *            return immediately
 *      math: 1. basic idea: fill each bit one by one
 *            2. we can use (k-1) / fac[i-1] + 1 to get the ith bit 
 *               because k range [1...fac[n]], it begins from i, and / result
 *               range from 0, then we first sub k by 1 and add 1 at last
 *            3. each time we get the vitual digit(aslo the position of 1...n)
 *               but some of them have been used, then we will use the used 
 *               vector to get the real one.
 *  gdb is very friendly !!!
 */
void init(int n)
{
	int i;
	fac[0] = 1;
	for (i = 1; i <= n; ++i) {
		fac[i] = fac[i-1] * i;
	}
}

void dfs(int n, int pos, char *result, int k)
{
	if (find) return;
	if (pos == n) {
		result[pos] = '\0';
		if (++count == k) {
			find = 1;
			return; 
		}
	}

	int i;
	for (i = 1; i <= n; ++i) {
		if (!used[i]) {
			used[i] = 1;
			result[pos] = i + '0';
			dfs(n, pos+1, result, k);
			// important !! otherwise the i will be added until n, 
			// that is to say, we will do something wrong additionally
			if (find) return; 
			used[i] = 0;
		}
	}
}

char *getPermutation(int n, int k) 
{
	count = 0;
	find = 0;
	memset(used, 0, sizeof(used));
	char *result = malloc(sizeof(int) * (n+2));
	dfs(n, 0, result, k);
	return result;
}

int get_real_digit(int n, int pos)
{
	int i, t = 0;
	for (i = 1; i <= n; ++i) {
		if (!used[i])
			if (++t == pos)
				return i;
	}
}
char *getPermutation1(int n, int k) 
{
	memset(used, 0, sizeof(used));
	char *result = malloc(sizeof(int) * (n+2));
	init(n);

	int i, tn = n;
	for (i = 0; i < tn; ++i) {
		int digit = (k - 1) / (fac[n-1]) + 1;// means the ith digit in 1 ... n if none of them is used
		int real_digit = get_real_digit(tn, digit);// but some have been used, then we should skip them

		result[i] = real_digit + '0';
		used[real_digit] = 1;

		k -= fac[n-1] * (digit - 1); 
		n--;
	}
	result[tn] = '\0';
	return result;
}

int main()
{
	int n, k;
	while (~scanf("%d %d", &n, &k)) {
		char *r = getPermutation1(n, k);
		printf("The %dth of %d permutation is %s\n", k, n, r);
		free(r);
	}

	return 0;
}
