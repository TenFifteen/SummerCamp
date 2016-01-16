/**
 * Problem: Given a string s, patition s such that every substring of the
 *          patition is a palinedrome. Return the minimum cuts of s.
 * Solve: copied from the discuss board.
 *        Say that it started at s[i] = 'b', and s[i-1,i+1] is a palindrome "aba":
 *        .......aba...
 *        |<-X->| ^
 *        |<---Y-->|
 *        And we know the least cuts for s[0,i-1) is X, then the least cuts for s[0,i+1] Y
 *        is not greater than X+1. Last, we need to find out all the palindromes in s[0,i+1]
 *        so as to minimize the number of cuts.
 * Tips: use n + 1 instead of n size of dp, because we use dp[i-j-1] will be out of range in
 *       the latter case.
 */
int minCut(string s) {
	int n = s.size();
	vector<int> dp(n+1, 0);
	for (int i = 0; i < n+1; ++i) dp[i] = i-1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; i-j>=0 && i+j < n && s[i-j] == s[i+j]; ++j) {
			dp[i+j+1] = min(dp[i+j+1], dp[i-j]+1);
		}
		for (int j = 0; i-j-1>=0 && i+j < n && s[i-j-1] == s[i+j]; ++j) {
			dp[i+j+1] = min(dp[i+j+1], dp[i-j-1]+1);
		}
	}

	return dp[n];
}
