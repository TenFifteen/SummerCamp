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
        cin >> num;
        count[num]++;
    }
    for (int i = 0; i < count.size(); ++i) {
        cout << count[i] << " ";
    }
    cout << endl;
    return 0;
}
