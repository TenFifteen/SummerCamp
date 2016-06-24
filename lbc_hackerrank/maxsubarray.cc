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
        
        int ans1 = arr[0], ans2 = ans1;
        int cur = ans1;
        for (int i = 1; i < n; ++i) {
            if (cur > 0) cur += arr[i];
            else cur = arr[i];
            ans1 = max(ans1, cur);
            
            if (ans2 < 0) ans2 = max(ans2, arr[i]);
            else if (arr[i] > 0) ans2 += arr[i];
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
