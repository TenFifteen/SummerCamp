#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        
        bool ok = true;
        int ans = 0;
        for (int i = n-1; i >= 0; --i) {
            if (arr[i] == i+1) continue;
            else if (arr[i-1] == i+1) {
                swap(arr[i], arr[i-1]);
                ans++;
            } else if (arr[i-2] == i+1) {
                swap(arr[i-2], arr[i-1]);
                swap(arr[i-1], arr[i]);
                ans += 2;
            } else {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            cout << ans << endl;
        } else {
            cout << "Too chaotic" << endl;
        }
        
    }
    return 0;
}
