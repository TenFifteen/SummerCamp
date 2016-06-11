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
        int n;
        cin >> n;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
            sort(grid[i].begin(), grid[i].end());
        }
        
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (grid[0][i] < grid[0][i-1]) ok = false;
            if (grid[i][0] < grid[i-1][0]) ok = false;
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] < grid[i][j-1] || grid[i][j] < grid[i-1][j]) {
                    ok = false;
                }
            }
        }
        
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
