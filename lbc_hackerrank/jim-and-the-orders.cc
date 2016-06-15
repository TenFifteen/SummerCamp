#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    while (cin >> n) {
        vector<pair<int, int>> arr(n);
        for (int i = 1; i <= n; ++i) {
            int t, d;
            cin >> t >> d;
            arr[i-1].first = t+d;
            arr[i-1].second = i;
        }

        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            cout << arr[i].second << " ";
        }
        cout << endl;
    }
    
    return 0;
}
