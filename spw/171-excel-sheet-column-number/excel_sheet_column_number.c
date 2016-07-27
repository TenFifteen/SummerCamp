/**
 * Problem: Given a column title appear in an Excel sheet, return its corresponding column number.
 * Solve: accumulation
 * Tips: no
 */
int titleToNumber(char* s) {
    int ans = 0;
    int len = strlen(s);
    int weight = 1;
    int i;
    for (i = len-1; i >= 0; --i) {
        ans += (s[i]-'A'+1)*weight;
        weight *= 26;
    }

    return ans;
}

class Solution {
    public:
        int titleToNumber(string s) {
            int ans = 0, fac = 1;
            int n = s.size();
            for (int i = n-1; i >= 0; --i) {
                ans += (s[i] - 'A' + 1) * fac;
                fac *= 26;
            }

            return ans;
        }

};
