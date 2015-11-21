/*
ID: libench1
PROG: sort3
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");

    int n;
    fin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        fin >> data[i];
    }

    vector<int> tmp(data);
    sort(tmp.begin(), tmp.end());

    int one_two = 0, two_one = 0;
    int one_three = 0, three_one = 0;
    int two_three = 0, three_two = 0;
    for (int i = 0; i < n; ++i) {
        if (tmp[i] == data[i]) continue;

        switch(data[i]) {
            case 1:
                if (tmp[i] == 2) {
                    one_two++;
                } else {
                    one_three++;
                }
                break;
            case 2:
                if (tmp[i] == 1) {
                     two_one++;
                } else {
                    two_three++;
                }
                break;
            case 3:
                if (tmp[i] == 1) {
                    three_one++;
                } else {
                     three_two++;
                }
                break;
            default:
                break;
        }
    }

    int ans = 0;
    int m = min(one_three, three_one);
    ans += m;
    one_three -= m;
    three_one -= m;

    m = min(one_two, two_one);
    ans += m;
    two_one -= m;
    one_two -= m;

    m = min(two_three, three_two);
    ans += m;
    two_three -= m;
    three_two -= m;

    ans += 2*max(one_two, two_one);

    fout << ans << endl;

    return 0;
}
