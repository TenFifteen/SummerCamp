/**
 * Problem: Given an integer n, return the number of trailing zoroes in n!.
 * Solve: find how many factor 5 the n! provide
 * Tips: see beauty of progamming. 
 */
int trailingZeroes(int n) {
	int count = 0;
	while (n) {
		count += (n /= 5);
	}

	return count;
}
