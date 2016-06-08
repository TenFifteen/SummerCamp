#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int D, M, Y;
    int d, m, y;
    cin >> d >> m >> y;
    cin >> D >> M >> Y;
    if (y > Y) cout << 10000 << endl;
    else if (y < Y) cout << 0 << endl;
    else if (m > M) cout << (m-M)*500 << endl;
    else if (m < M) cout << 0 << endl;
    else if (d > D) cout << (d-D)*15 << endl;
    else cout << 0 << endl;
    
    return 0;
}
