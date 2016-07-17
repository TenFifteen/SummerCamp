#include <iostream>
#include <vector>

using namespace std;

void getNext(const string &p, vector<int> &next) {
    int n = p.size();
    int i = 0, j = -1;

    next[0] = -1;
    while (i < n - 1) {
        if (j == -1 || p[i] == p[j]) {
            ++j;
            ++i;
            next[i] = j;

        } else {
            j = next[j];

        }
    }
}


int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    if (n > m) return -1;
    if (n == 0) return 0;

    vector<int> next(n);
    getNext(needle, next);

    int i = 0, j = 0;
    while (i < m && j < n) {
        // warning !! || instead of &&
        if (j == -1 || haystack[i] == needle[j]) {
            ++i; ++j;

        } else {
            j = next[j];

        }

    }

    if (j == n) return i - j;
    return -1;

}

int main()
{
    string s = "songpengwei", p = "peng";
    cout << strStr(s, p) << endl;

    return 0;
}
