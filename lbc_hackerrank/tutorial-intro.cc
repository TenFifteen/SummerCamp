#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int val, n;
    cin >> val >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int left = 0, right = n-1;
    while (left < right) {
        int mid = (left+right)/2;
        if (arr[mid] > val) {
            right = mid-1;
        } else if (arr[mid] < val) {
            left = mid+1;
        } else {
            left = mid;
        }
    }
    cout << left << endl;
    
    return 0;
}
