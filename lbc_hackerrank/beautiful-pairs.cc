#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> count(1001, 0);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        count[num]++;
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (count[num]-- > 0) ans++; 
    }
    
    if (ans == n) ans--;
    else ans++;
    cout << ans << endl;
    
    return 0;
}
