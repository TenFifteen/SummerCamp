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
    vector<int> count(100, 0), key(n);
    vector<string> value(n);
    for (int i = 0; i < n; ++i) {
        cin >> key[i] >> value[i];
        count[key[i]]++;
    }
    
    for (int i = 1; i < count.size(); ++i) {
        count[i] += count[i-1];
    }
    
    vector<string> ans(n);
    vector<int> original_key(n);
    for (int i = n-1; i >= 0; --i) {
        count[key[i]]--;
        int index = count[key[i]];
        ans[index] = value[i];
        original_key[index] = i;
    }
    
    for (int i = 0; i < n; ++i) {
        if (original_key[i] < n/2) cout << "- ";
        else cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
