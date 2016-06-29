#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

/**
 * Problem: judege if a parentheses string is valid or not
 * Thoughts: traverse the string and mantain a stack, every time fetch
 *			character from the string and a character from the stack if it is not empty.
 *			then we can make a judege or a action each time.
 *
 *			finally, we can tell the answer by the state of the stack
 * Tips: a table and the order of judgement
 */
bool isValid(string s)
{
	int len = s.size();
	if (len == 0)  return true;
	if (len & 0x1)  return false;

	map<char, char> p_table;
	p_table['('] = ')';
	p_table['['] = ']';
	p_table['{'] = '}';

	stack<char> left;
	for (int i = 0; i < len; ++i) {
		char now = s[i];
		if (p_table.find(now) != p_table.end()) {
			left.push(now);
		} else {
			if (left.empty() || p_table[left.top()] ^ now)  {
				return false;
			}
			left.pop();
		}

		/**
		 * the sequence of the judgement can result in different lengh of the code
		 *
		if (left.empty()) {
			if (p_table.find(now) == p_table.end()) {
				return false;
			} else {
				left.push(now);
			}
		} else {
			char need = p_table[left.top()];
			if (p_table.find(now) == p_table.end()) {
				if (need ^ now) {
					return false;
				} else {
					left.pop();
				}
			} else {
				left.push(now);
			}
		}
		*/
	}

	return left.empty();
}

int main()
{
	string s;
	while (cin >> s) {
		if (isValid(s))
			cout << s <<  " is a valid parentheses string!" << endl;
		else
			cout << s <<  " is not a valid parentheses string!" << endl;
	}

	return 0;
}
class Solution {
public:
    bool isValid(string s) {
        static unordered_map<char, char> table;
        table['('] = ')';
        table['['] = ']';
        table['{'] = '}';

        stack<char> left;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                left.push(s[i]);
            } else {
                if (left.empty() || s[i] != table[left.top()])
                    return false;
                left.pop();
            }
        }

        return left.empty();
    }
};
