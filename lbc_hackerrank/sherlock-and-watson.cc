#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    k %= n;
    for (int i = 0; i < q; ++i) {
        int index;
        cin >> index;
        index -= k;
        if (index < 0) index += n;
        cout << arr[index] << endl;
    }
    
    return 0;
}
