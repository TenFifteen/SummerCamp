#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s, int start, int end) {
	while (start < end) {
		char temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		++start, --end;
	}
}

int is_blank(char c) {
	return (c == ' ' || c == '\t');
}

/**
 * Problem: Given an input string, reverse the string word by word.
 * Solve: reverse all character first, then reverse each word.
 * Tips: watch out for the blanks.
 */
void reverseWords(char *s) {
	if (s == NULL) return;

	int len = strlen(s);

	int i = 0;
	/* remove all the extra blanks */
	while (i < len && is_blank(s[i])) i++;
	int count = 0;
	for (; i < len; ++i) {
		s[count++] = s[i];
		if (is_blank(s[i])) {
			while (i+1 < len && is_blank(s[i+1]))  ++i;
		}
	}
	s[count] = '\0';
	if (count-1 > 0 && is_blank(s[count-1])) {
		s[count-1] = '\0';
		--count;
	}

	/*reverse twice*/
	reverse(s, 0, count-1);
	int start = 0, end = 0;
	for (i = 0; i < count; ++i) {
		if (is_blank(s[i])) {
			end = i - 1;
			reverse(s, start, end);
			start = i + 1;
		}
	}
	// warn!! reverse the last word
	reverse(s, start, count-1);
}
int main()
{
	char s[100];
	while (gets(s)) {
		printf("Before reverse: %s\n", s);
		reverseWords(s);
		printf("After reverse: %s\n", s);
	}

	return 0;
}


class Solution {
public:
    void reverse(string &s, int l, int r) {
        while (l < r)
            swap(s[l++], s[r--]);
    }

    void reverseWords(string &s) {
        int n = s.size();
        int i = 0, pos = 0;

        // remove heading and tailing space.
        while (i < n && s[i] == ' ') ++i;
        while (n > i && s[n-1] == ' ') --n;

        // composite the middle space.
        while (i < n) {
            s[pos++] = s[i++];
            if (s[i-1] == ' ') {
                while (i < n && s[i] == ' ')
                    ++i;
            }
        }

        // r must be initialized to l-1
        s = s.substr(0, pos);
        reverse(s, 0, pos-1);
        int l = 0, r = -1;
        for (i = 0; i < pos; ++i) {
            if (s[i] == ' ') {
                reverse(s, l, r);
                r = i;
                l = i+1;
            } else {
                ++r;
            }
        }
        reverse(s, l, r);
    }
};
