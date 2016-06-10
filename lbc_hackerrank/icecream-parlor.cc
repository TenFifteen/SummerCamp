#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> m >> n;
        unordered_map<int, int> hash;
        int i1, i2;
        for (int i = 1; i <= n; ++i) {
            int num;
            cin >> num;
            if (hash.find(m-num) != hash.end()) {
                i1 = hash[m-num];
                i2 = i;
            }
            hash[num] = i;
        }
        cout << i1 << " " << i2 << endl;
    }
    return 0;
}
