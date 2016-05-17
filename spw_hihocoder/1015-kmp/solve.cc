#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNext(vector<int> &next, string &word) {
    int n = word.size();

    int i = 0, j = -1;
    next[0] = -1;
    while (i < n) {
        if (j == -1 || word[i] == word[j]) {
            ++i, ++j;
            // because word[i] lose match && word[i] == word[j]
            // then we only need slide the next array
            if (word[i] != word[j])
                next[i] = j;
            else
                next[i] = next[j];
        } else {
            j = next[j];
        }
    }
}

int kmp(string &src, string &pattern) {
    int m = src.size(), n = pattern.size();

    // add a space to handle find one
    vector<int> next(n+1, 0);
    getNext(next, pattern);

    int i = 0, j = 0;
    int cnt = 0;
    while (i < m) {
        if (j == -1 || src[i] == pattern[j]) {
            ++i, ++j;
        } else {
            j = next[j];
        }

        if (j == n) {
            ++cnt;
            j = next[j];
        }
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string src, pattern;
        cin >> pattern >> src ;
        cout << kmp(src, pattern) << endl;
    }

    return 0;
}
