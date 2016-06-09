#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<pair<int,int>> ans;
    int diff = INT_MAX;
    for (int i = 1; i < n; ++i) {
        if (arr[i] - arr[i-1] < diff) {
            ans.clear();
            ans.push_back(make_pair(arr[i-1], arr[i]));
            diff = arr[i] - arr[i-1];
        } else if (arr[i] - arr[i-1] == diff) {
            ans.push_back(make_pair(arr[i-1], arr[i]));
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << " ";
    }
    cout << endl;
    return 0;
}
