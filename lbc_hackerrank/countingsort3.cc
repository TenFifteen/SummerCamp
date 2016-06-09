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
    vector<int> count(100, 0);
    for (int i = 0; i < n; ++i) {
        int num;
        string s;
        cin >> num >> s;
        count[num]++;
    }
    int total = 0;
    for (int i = 0; i < count.size(); ++i) {
        total += count[i];
        cout << total << " ";
    }
    cout << endl;
    return 0;
}
