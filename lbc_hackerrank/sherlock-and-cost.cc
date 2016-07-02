#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        
        vector<int> choose(n, 0), not_choose(n, 0);
        for (int i = 1; i < n; ++i) {
            choose[i] = max(not_choose[i-1] + arr[i] - 1, choose[i-1]);
            not_choose[i] = max(not_choose[i-1], choose[i-1] + arr[i-1] - 1);
        }
        cout << max(choose[n-1], not_choose[n-1]) << endl;
    }
    return 0;
}
