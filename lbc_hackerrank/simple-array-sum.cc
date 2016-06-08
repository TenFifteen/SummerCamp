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
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int number;
        cin >> number;
        sum += number;
    }
    cout << sum << endl;
    return 0;
}
