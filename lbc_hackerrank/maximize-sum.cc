#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        vector<long long> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        
        set<long long> s;
        s.insert(0);
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            sum %= m;
            if (s.lower_bound(sum+1) != s.end()) {
                ans = max(ans, sum+m-*s.lower_bound(sum+1));
            } else {
                ans = max(ans, sum-*s.lower_bound(0));
            }
            s.insert(sum);
        }
        cout << ans << endl;
    }
    return 0;
}
