#include <stdio.h>

int isMatch(const char *s, const char *p) {
    const char *c;

    for (c = p; *s; ++s, c = p) {
        if (*p != '*') {
            ++p;

        } else if (isMatch(s, p+1)) {
            return 1;

        }

        if (*s == 0 || *c != '?' && *c != '*' && *c != *s) return 0;
    }

    return *p == 0;

}
int main()
{
    char s[20];
    char p[20];

    scanf("%s%s", s, p);
    isMatch(s, p);

    return 0;
}
