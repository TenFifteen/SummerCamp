#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char str[1000002], p[10002];
int Next[10002];

void getNext() {
    int len = strlen(p);
    Next[0] = -1;
    int k = -1, j = 0;

    while (j < len) { // here we get one more next
        if (k == -1 || p[j] == p[k]) {
            k++;
            j++;
            if (p[j] != p[k]) Next[j] = k;
            else Next[j] = Next[k];
        } else {
            k = Next[k];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", p);
        scanf("%s", str);

        getNext();

        int ans = 0;
        int sLen = strlen(str), pLen = strlen(p);
        int i = 0, j = 0;
        while (i < sLen) {
            if (j == pLen) {
                ans++;
            }

            if (j == -1 || str[i] == p[j]) {
                i++;
                j++;
            } else {
                j = Next[j];
            }
        }
        if (j == pLen) ans++;

        printf("%d\n", ans);
    }

    return 0;
}
