#include <iostream>
#include <string>

using namespace std;
bool judge(string s) {
	bool flag = true;
	int left = 0, right = s.size() - 1;
	while (left < right) {
		if (s[left] != s[right]) {
			flag = false;
			break;
		}
		left++;
		right--;
	} 

	return flag;
} 

bool isPalindrome(string s) {
	string p = "";
	int i = 0, len = s.size();

	int diff = 'a' - 'A';
	while (i < len) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			p += s[i];
		} else if (s[i] >= 'A' && s[i] <= 'Z'){
			p += (s[i] + diff);
		}

		++i;
	}

	return judge(p);
}
int main()
{
	string s;
	while (cin >> s) {
		if (isPalindrome(s))
			cout << s << " is palindrom." << endl;
		else 
			cout << s << " is not palindrom." << endl;
	}

	return 0;
}
