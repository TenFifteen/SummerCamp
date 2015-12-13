#include <string>
#include <vector>

bool isIsomorphic(string s, string t) {
    int l = s.size();
    if (l != t.size()) return false;

    if (l == 0) return true;

    string a, b;
    for (int i = 0; i < l; ++i) {
        if (s[i] == s[0] && t[i] != t[0] || t[i] == t[0] && s[i] != s[0]) {
            return false;
        } else {
            if (s[i] != s[0] && t[i] != t[0]) {
                a += s[i];
                b += t[i];
            }
        }
    }
    return isIsomorphic(a, b);
}

/**
 * Problem: Given two strings s and t, determine if they are isomorphic.
 * Solve: Traversal and reset each character use the new assigned character.
 * Tips: Sentences order.
 */
bool isIsomorphic(string s, string t) {
    int l = s.size();
    if (l != t.size()) return 0;

    int used1[256] = {0};
    int used2[256] = {0};
    int c1 = 1;
    int c2 = 1;
    for (int i = 0; i < l; ++i) {
        if (!used1[s[i]]) {
            used1[s[i]] = c1++;

        }
        s[i] = used1[s[i]];

        if (!used2[t[i]]) {
            used2[t[i]]  = c2++;

        }
        t[i] = used2[t[i]];
        if (c1 != c2) return false;

    }

    return s == t;

}
int main() {

}
