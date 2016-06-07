#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getFloor(int n) {
    int ret = n;
    while (ret*ret > n) ret--;
    return ret;
}

int getCeiling(int n) {
    int ret = 0;
    while (ret * ret <= n) ret++;
    if ((ret-1)*(ret-1) == n) return ret-1; // easy to be wrong....
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin >> s;
    
    int len = s.size();
    int ceil = getCeiling(len);
    int floor = getFloor(len);
    if (ceil * floor < len) floor = ceil;
    
    vector<vector<char>> ans(floor, vector<char>(ceil));
    int index = 0;
    for (int i = 0; i < floor; ++i) {
        for (int j = 0; j < ceil; ++j) {
            if (index < len) {
                ans[i][j] = s[index++];
            } else {
                ans[i][j] = ' ';
            }
        }
    }
    
    for (int i = 0; i < floor; ++i) cout << ans[i][0];
    
    for (int j = 1; j < ceil; ++j) {
        cout << " ";
        for (int i = 0; i < floor; ++i) {
            if (ans[i][j] == ' ') break;
            cout << ans[i][j];
        }
    }
    cout << endl;
    
    return 0;
}
