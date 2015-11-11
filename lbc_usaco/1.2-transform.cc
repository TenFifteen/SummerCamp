/*
ID: libench1
PROG: transform
LANG: C++11
*/
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<char > > rotate90(vector<vector<char> > pattern) {
    auto ret = pattern;
    int n = pattern.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret[j][n-1-i] = pattern[i][j];
        }
    }

    return ret;
}

vector<vector<char> > rotate180(vector<vector<char> > pattern) {
    auto ret = pattern;
    int n = pattern.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret[n-1-i][n-1-j] = pattern[i][j];
        }
    }

    return ret;
}

vector<vector<char> > rotate270(vector<vector<char> > pattern) {
    auto ret = pattern;
    int n = pattern.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret[n-1-j][i] = pattern[i][j];
        }
    }

    return ret;
}

vector<vector<char> > reflection(vector<vector<char> > pattern) {
    auto ret = pattern;
    int n = pattern.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret[i][n-1-j] = pattern[i][j];
        }
    }

    return ret;
}

bool isSame(vector<vector<char> > pattern, vector<vector<char> > transform) {
     int n = pattern.size();
     for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
             if (pattern[i][j] != transform[i][j]) {
                 return false;
             }
         }
     }
     return true;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    int n;
    fin >> n;
    vector<vector<char> > pattern(n, vector<char>(n)), transform(n, vector<char>(n));
    for (int i = 0;i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> pattern[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> transform[i][j];
        }
    }

    int ans = 7;
    if (isSame(rotate90(pattern), transform)) {
        ans = 1;
    } else if (isSame(rotate180(pattern), transform)) {
        ans = 2;
    } else if (isSame(rotate270(pattern), transform)) {
        ans = 3;
    } else if (isSame(reflection(pattern), transform)) {
         ans = 4;
    } else if (isSame(pattern, transform)) {
         ans = 6;
    } else {
        if (isSame(rotate90(reflection(pattern)), transform)) {
            ans = 5;
        } else if (isSame(rotate180(reflection(pattern)), transform)) {
            ans = 5;
        } else if (isSame(rotate270(reflection(pattern)), transform)) {
            ans = 5;
        }
    }

    fout << ans << endl;

    return 0;
}
