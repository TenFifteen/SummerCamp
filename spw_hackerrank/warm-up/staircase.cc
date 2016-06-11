#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    string line(n, ' ');
    while (n--) {
        line[n] = '#';
        cout << line << endl;
    }

    return 0;
}

