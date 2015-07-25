#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Problem: The gray code is a binary numeral system where two successive values differ in only one bit.
 * Solve: derive from grayCode(0), then change the first bit of ervery last answer from 0 to 1
 * Tips: the count of the sequence must equal pow(2, n)
 */
vector<int> grayCode(int n) 
{
	int c = pow(2, n);

	vector<int> ans(c, 0);
	int total = 2;
	for (int i = 1; i <= n; i++) {
		int pre = 0x1 << (i-1);
		for (int j = total/2-1; j >= 0; --j) {
			ans[total-1-j] = ans[j] | pre;
		}
		total = total * 2;
	}

	return ans;
}

int main()
{
	int n;
	while (cin >> n) {
		vector<int> ans = grayCode(n);
		cout << "================" << endl;
		cout << n << " : " << endl;
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i] << endl;
		}
	}

	return 0;
}
