/**
 * Problem: find the maximal sum of hourglass shape in 6*6 2D array.
 * Solve: vertical bar of length 3
 * Tips: no
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
        for(int arr_j = 0;arr_j < 6;arr_j++){
            cin >> arr[arr_i][arr_j];
        }
    }

    vector<vector<int>> sum(4, vector<int>(6, 0));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = i; k < i+3; ++k) {
                sum[i][j] += arr[k][j];
            }
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < 4; ++i) {
        for (int j = 2; j < 6; ++j) {
            ans = max(ans, sum[i][j]+sum[i][j-1]+sum[i][j-2]-arr[i+1][j]-arr[i+1][j-2]);
        }
    }

    cout << ans << endl;
    return 0;
}

