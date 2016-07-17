#include <stdio.h>
#include <string.h>

/**
 * use a vector to judge if one character has existed or not
 * the vector does not store 0/1 only but the next palce of the apprance of charater
 * so we can jump to the place if we find one repeated character
 */
int lengthOfLongestSubstring(char* s) {
    int flag[256] = {0};

    int len = strlen(s);
    if (len == 0 || len == 1) return len; // must keep in mind!! -> the bounded check

    int i, l = 0, max_l = 1;
    for (i = 0; i < len; ++i) {
        if (flag[s[i]]) {
            max_l = max_l < l ? l : max_l;
            i = flag[s[i]];
            l = 0;

            memset(flag, 0, sizeof(flag));
        }

        flag[s[i]] = i+1;// if assign i, then there is some problem when i = 0
        ++l;
    }
    max_l = max_l < l ? l : max_l; // can't be ommitted because the loop may not step into the 'if (flag[s[i]])'

    return max_l;
}

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> index;

    int ans = 0, n = s.size(), start = 0;
    for (int i = 0; i < n; ++i) {
        char ch = s[i];
        if (index.find(ch) == index.end()) {
            index[ch] = i;
            ans = max(ans, (int)index.size());
        } else {
            int end = index[ch];
            for (int j = start; j < end; ++j) {
                index.erase(s[j]);
            }
            start = end + 1;
            index[ch] = i;
        }
    }

    return ans;
}

int main()
{
    char input[1000];
    while (~scanf("%s", input)) {
        printf("%d\n", lengthOfLongestSubstring(input));
    }

    return 0;
}
