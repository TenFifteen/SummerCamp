/*
ID: libench1
PROG: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string s1, s2;
    while (fin >> s1 >> s2) {
        int a = 1, b = 1;
        for (int i = 0; i < s1.size(); ++i) {
            a *= (s1[i]-'A'+1);
        }
        for (int i = 0; i < s2.size(); ++i) {
            b *= (s2[i]-'A'+1);
        }
        if (a % 47 == b % 47) {
            fout << "GO" << endl;
        } else {
            fout << "STAY" << endl;
        }
    }
    return 0;
}
