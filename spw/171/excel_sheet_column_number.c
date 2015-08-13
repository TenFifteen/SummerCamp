/**
 * Problem: Given a column title appear in an Excel sheet, return its corresponding column number.
 * Solve: accumulation
 * Tips: no
 */
int titleToNumber(char* s) {
	int ans = 0;
	int len = strlen(s);
	int weight = 1;
	int i;
	for (i = len-1; i >= 0; --i) {
		ans += (s[i]-'A'+1)*weight;
		weight *= 26;
	}

	return ans;
}
