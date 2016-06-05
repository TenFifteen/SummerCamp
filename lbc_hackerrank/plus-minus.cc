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
    int neg = 0, pos = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num < 0) neg++;
        else if (num > 0) pos++;
        else zero++;
    }
    
    printf("%.6lf\n", (double)pos / n);
    printf("%.6lf\n", (double)neg / n);
    printf("%.6lf\n", (double)zero / n);
    
    return 0;
}
