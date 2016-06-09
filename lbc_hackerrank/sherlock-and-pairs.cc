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
        int n;
        cin >> n;
        unordered_map<int, long long> hash; // in will overflow.
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            hash[num]++;
        }
        
        long long ans = 0;
        for (auto h : hash) {
            ans += h.second * (h.second-1);
        }
        cout << ans << endl;
    }
    return 0;
}
