/*
题目的坑在于，15还要写成quarter。。。。
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string toString(int n) {
    static const vector<string> mapping = {"", "one", "two", "three", "four", "five", "six", "seven",
                     "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                     "twenty"};
    if (n <= 20) return mapping[n];
    return mapping[20] + " " + mapping[n-20];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int h, m;
    cin >> h >> m;
    if (m == 0) {
        cout << toString(h) << " o' clock" << endl;
    } else if (m == 30) {
        cout << "half past " << toString(h) << endl;
    } else if (m < 30) {
        if (m == 15) cout << "quarter past " << toString(h) << endl;
        else cout << toString(m) << " minutes past " << toString(h) << endl;
    } else {
        if (m == 45) cout << "quarter to " << toString(h+1) << endl;
        else cout << toString(60-m) << " minutes to " << toString(h+1) << endl;
    }
    return 0;
}
