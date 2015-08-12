#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <utility> 

using namespace std;

/**
 * Problem: Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 * Solve: use a map to keep in mind where the loop begins.
 * Tips: 1. use long.
 *       2. handle sign
 *       3. the map can be map<int, int> ? think about it.
 *       yes, we can use it, but in this way, we must see forward. that is, if r is not in the map, then we let
 *       ans += (r*10/d), because the same r corresponding to the same r*10/d
 */
string fractionToDecimal(int numerator, int denominator) 
{
	int sign = 1;
	long nn = numerator, dd = denominator;
	if (numerator < 0) {sign = -sign, nn = -nn;}
	if (denominator < 0) {sign = -sign, dd = -dd;}


	long num = nn / dd;
	string ans = "";
	while (num) {
		ans = (char)('0' + num % 10) + ans;
		num /= 10;
	}
	if (ans == "") ans = "0";
	if (sign < 0 && nn != 0) ans = '-' + ans;

	long r = nn % dd;
	if (r == 0) return ans;

	map<pair<int,int>, int> remainder_index;
	string fra = "";
	for (r *= 10; r != 0; r*= 10) {
		int n = r / dd;
		r = r % dd;
		if (r == 0) {
			fra += (char)(n + '0');
			break;
		} else {
			pair<int, int> t(n, r);
			if (remainder_index.count(t) != 0) {
				ans = ans + "." + fra.substr(0, remainder_index[t]) + "(" + fra.substr(remainder_index[t]) + ")";
				return ans;
			}
			remainder_index[t] = fra.size();
		}
		fra += (char)(n + '0');
	}

	return ans + "." + fra;
} 

string fractionToDecimal1(long numerator, long denominator) 
{
	if (numerator == 0) return 0;
	if (denominator == 0) return "NaN";

	int sign = 1;
	if (numerator < 0) {sign = -sign, numerator = -numerator;}
	if (denominator < 0) {sign = -sign, denominator = -denominator;}

	string ans = to_string(numerator/denominator);
	if (sign < 0) ans = '-' + ans;

	long r = numerator % denominator;
	if (r == 0) return ans;
	ans += ".";

	map<pair<int,int>, int> remainder_index;
	for (r *= 10; r != 0; r*= 10) {
		int n = r / denominator;
		r = r % denominator;
		if (r == 0) {
			ans += (char)(n + '0');
			break;
		} else {
			pair<int, int> t(n, r);
			if (remainder_index.count(t) != 0) {
				ans.insert(remainder_index[t], "(");
				ans += ")";
				break;
			}
			remainder_index[t] = ans.size();
		}
		ans += (char)(n + '0');
	}

	return ans;
} 



int main()
{
	int a, b;
	while (~scanf("%d %d", &a, &b)) {
		printf("%d/%d is %s\n", a, b, fractionToDecimal1(a, b).c_str());
	}

	return 0;
}
