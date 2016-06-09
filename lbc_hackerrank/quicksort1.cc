#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int val = arr[0];
    int i = 0, j = 0, k = n-1;
    while (i <= k) {
        if (arr[i] < val) {
            swap(arr[j++], arr[i++]);
        } else if (arr[i] > val) {
            swap(arr[i], arr[k--]);
        } else {
            i++;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
