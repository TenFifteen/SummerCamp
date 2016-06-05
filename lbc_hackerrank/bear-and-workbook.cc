#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin >> n >> k;
    int page = 1, ans = 0;
    for (int i = 0; i < n; ++i) {
        int problem;
        cin >> problem;
        for (int p = 1; p <= problem;) {
            int next = min(p + k, problem + 1);
            if (page >= p && page < next) ans++;
            page++;
            p = next;
        }
    }
    cout << ans << endl;
    
    return 0;
}
