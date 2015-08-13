#include <iostream>
#include <string>

using namespace std;

/**
 * Problem: Given an positive integer, return its corresponding column title 
 *          appears in an Excel sheet.
 * Solve: binhex(26), but when n = 26, we use Z to represent, when n = 52, we use
 *        AZ, that is, when n % 26 == 0, we borrow one bit from the high order, and
 *        convert it to 'Z'.
 * Tips: not so clear
 */
string convertToTitle(int n) 
{
	string ans = "";
	while (n) {
		int now = n % 26; 
		n /= 26;

		if (now == 0) {
			ans = 'Z' + ans;
			n--;
		} else { 
			ans = (char)(now - 1 + 'A') + ans;
		}
	}	  

	return ans;
}

int main()
{
	int n;
	while (cin >> n) {
		cout << "The title is "	<<  convertToTitle(n) << endl;
	}

	return 0;
}
