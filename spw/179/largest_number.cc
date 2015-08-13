#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(char* a, char* b) {
	string blank = "";
	string temp1 = blank + a + b;
	string temp2 = blank + b + a;
	return temp1 > temp2;
}

/**
 * Problem: Given a list of non negative integers, arrange them such that they form the largest
 *          number.
 * Solve: the key point lays on the compare function. That is compare a+b and b+a in lexicographical order.
 * Tips: when we submit, the leetcode platform require that the cmp is static.
 */
string largestNumber(vector<int>& nums) {
	int n = nums.size();
	vector<char *> s(n, NULL);
	for (int i = 0; i < n; ++i) {
		s[i] = new char[16];
		sprintf(s[i], "%d", nums[i]);
	}
	sort(s.begin(), s.end(), cmp);
	string ans = "";
	for (int i = 0; i < n; ++i) {
		ans += s[i];
	}

	for (int i = 0; i < n; ++i) {
		free(s[i]);
	}
	return ans;
}
int main()
{
	int arr[100];
	int n;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; ++i)	{
			scanf("%d", &arr[i]);
		}
		vector<int> nums(arr, arr+n);
		printf("The largest number is %s\n", largestNumber(nums).c_str());
	}

	return 0;
}
