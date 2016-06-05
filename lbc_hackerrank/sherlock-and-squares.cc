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
        int A, B;
        cin >> A >> B;
        int ans = 0;
        for (long long i = 1; i*i <= B; ++i) {
            if (i*i >= A) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
