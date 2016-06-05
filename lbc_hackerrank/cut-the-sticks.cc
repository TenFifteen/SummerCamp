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
    vector<int> sticks(n);
    for (int i = 0; i < n; ++i) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());
    int index = 0;
    while (index < n) {
        cout << n-index << endl;
        int next = index+1;
        while (next < n && sticks[next] == sticks[index]) next++;
        index = next;
    }
    
    return 0;
}
