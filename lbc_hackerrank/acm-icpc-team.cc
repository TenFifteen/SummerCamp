#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int num = 0;
            for (int k = 0; k < m; ++k) {
                if (arr[i][k] == '1' || arr[j][k] == '1') num++;
            }
            if (num > ans) {
                ans = num;
                cnt = 1;
            } else if (num == ans) {
                cnt++;
            }
        }
    }
    
    cout << ans << endl;
    cout << cnt << endl;
    
    return 0;
}
