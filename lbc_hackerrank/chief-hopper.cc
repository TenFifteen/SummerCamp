#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        
        int left = 0, right = 1000000;
        while (left < right) {
            int mid = (left + right) / 2;
            bool ok = true;
            long long energy = mid;
            for (int i = 0; i < n; ++i) {
                if (energy > arr[i]) energy += (energy - arr[i]);
                else energy -= (arr[i] - energy);
                if (energy < 0) {
                    ok = false;
                    break;
                }
                if (energy > 1000000) break; // prevent overflow.
            }
            
            if (ok) right = mid;
            else left = mid+1;
        }
        cout << left << endl;
    }
    return 0;
}
