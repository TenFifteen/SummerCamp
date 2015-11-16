/*
ID: libench1
PROG: numtri
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");

    int n;
    fin >> n;
    vector<vector<int> > triangle(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            fin >> triangle[i][j];
        }
    }

    for (int i = n-2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    fout << triangle[0][0] << endl;

    return 0;
}
