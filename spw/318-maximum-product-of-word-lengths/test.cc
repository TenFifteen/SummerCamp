#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<string>& words) {
    int n = words.size();
    if (n < 2) return 0;

    vector<unsigned int> bitmap(n, 0);
    for (int i = 0; i < n; ++i) {
        for (char c : words[i]) {
            bitmap[i] |= 1 << c - 'a';
        }
    }

    int res  = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if ((bitmap[i] & ~bitmap[j]) == bitmap[i])
                res = max(res, (int)words[i].size() * (int)words[j].size());
        }
    }

    return res;
}

int main() {
    return 0;
}
