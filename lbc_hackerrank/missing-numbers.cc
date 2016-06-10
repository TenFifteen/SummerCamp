#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<int, int> hash;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        hash[num]++;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        hash[num]--;
    }
    for (auto h : hash) {
        if (h.second != 0) cout << h.first << " ";
    }
    cout << endl;
    
    return 0;
}
