#include <cstdio>
#include <vector>

using namespace std;

/**
 * Problem: Given a non-negative number represented as an array of digits, plus one to the number.
 *          The digits are stored such that the most significant digit is at the head of the list.
 * Solve: traverse from the last to the first
 */
vector<int> plusOne(vector<int> &digits) 
{
	vector<int> ans(digits.size());
	int carry = 1; 
	for (int i = digits.size() - 1; i >= 0 ; --i) {
		int digit = digits[i] + carry;
		ans[i] = digit % 10;
		carry = digit / 10;
	}
	if (carry) {
		ans.insert(ans.begin(), 1);
	}

	return ans;
}

int main()
{

}
