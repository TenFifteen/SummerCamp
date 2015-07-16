/**
 * Problem: give an integer and find all the possible parentheses' sequences
 * Solve: find a method in the disscuss board!!
 *		  limiting condition: place the left parenthese first,
 *		  then we need a right one. Along with this way, we find
 *		  that we can use two conters. First sub left:n and add 
 *		  the right at the same time. then sub right.
 * Tips: m and n must be greater than 0
 *
 */
void sub(vector<string> &ans, string now, int n, int m) {
	if (!m && !n) {
		ans.push_back(now);
	}    

	if (n > 0) {
		sub(ans, now+'(', n-1, m+1);
	}

	if (m > 0) {
		sub(ans, now+')', n, m-1);
	}
} 

vector<string> generateParenthesis(int n) {
	vector<string> ans;
	sub(ans, "", n, 0);
	return ans;
}
