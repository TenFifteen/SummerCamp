#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> arr(n);
        vector<int> pos(n+1);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            pos[arr[i]] = i;
        }
        
        for (int i = n; i >= 1 && k > 0; --i) {
            if (pos[i] == n-i) continue;
            swap(arr[n-i], arr[pos[i]]);
            pos[arr[pos[i]]] = pos[i];
            k--;
        }
        
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
