题目：给定模式串p和原始串s，问s中模式串p出现的次数。
解题：KMP算法的应用。注意每次匹配后，i和j不是从头开始匹配，而是利用next数组，模式串移动到next[l2]的位置。

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> getNext(string &s) {
	int l = s.size();
	vector<int>next(l + 1, -1);
	int j = -1, i = 0;
	while(i < l) {
		if(j == -1 || s[i] == s[j]) {
			i++; 
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
	return next;
}
int main() {
	int n;
	string p, s;
	cin >> n;
	for(int t = 1; t <= n; t++) {
		cin >> p >> s;
		vector<int>next = getNext(p);
		int i = 0, j = 0, l2 = p.size(), l1 = s.size(), res = 0;
		while(i < l1) {
			while(i < l1 && j < l2) {
				if(j == -1 || s[i] == p[j]) {
					i++;
					j++;
				} else {
					j = next[j];
				}
			}
			if(j == l2)  {
				res++;
				j = next[l2];
			}
		}
		cout << res << endl;
	}
	return 0;
}