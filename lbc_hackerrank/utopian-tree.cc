#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int height = 1;
        for (int i = 0; i < n;) {
            height *= 2;
            i++;
            if (i < n) {
                height++;
                i++;
            }
        }
        cout << height << endl;
    }
    return 0;
}
