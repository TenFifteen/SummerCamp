#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int h, m, s;
    char str[4];
    scanf("%d:%d:%d%s", &h, &m, &s, str);
    if (str[0] == 'P') {
        if (h < 12) h += 12;
    } else {
        if (h == 12) h = 0;
    }
    if (h < 10) cout << 0;
    cout << h << ":";
    if (m < 10) cout << 0;
    cout << m << ":";
    if (s < 10) cout << 0;
    cout << s << endl;
    return 0;
}
