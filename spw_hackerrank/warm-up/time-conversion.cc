/**
 * Problem: Given a time in AM/PM format, convert it to military (-hour) time.
 * Solve:12:00:00am is 00:00:00 and 12:00:00pm is 12:00:00
 * Tips: no
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;

    string t = time.substr(8);
    int h = (time[0] - '0') * 10 + (time[1]-'0');
    if (t == "AM") {
        if (h == 12)
            cout << "00" << time.substr(2, 6) << endl;
        else
            cout << time.substr(0, 8) << endl;
    } else {
        if (h != 12) h += 12;
        cout << h << time.substr(2, 6) << endl;
    }
    return 0;
}

