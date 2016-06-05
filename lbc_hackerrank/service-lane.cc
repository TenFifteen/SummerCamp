#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, t;
    cin >> n >> t;
    vector<int> lane(n);
    for (int i = 0; i < n; ++i) {
        cin >> lane[i];
    }
    for (int i = 0; i < t; ++i) {
        int left, right;
        cin >> left >> right;
        int ans = lane[right];
        for (int j = left; j < right; ++j) {
            ans = min(lane[j], ans);
        }
        cout << ans << endl;
    }
    return 0;
}
