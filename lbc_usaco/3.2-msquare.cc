/*
ID: libench1
PROG: msquare
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

typedef int item[8];

struct square {
    item data;
    char trans;
    bool operator< (const square &s) const {
        for (int i = 0; i < 8; ++i) {
            if (data[i] < s.data[i]) {
                return true;
            } else if (data[i] > s.data[i]) {
                return false;
            }
        }

        return false;
    }

    bool operator== (const square &s) const {
        for (int i = 0; i < 8; ++i) {
            if (data[i] != s.data[i]) {
                return false;
            }
        }

        return true;
    }

    square(){}

    square(const square &s) {
        for (int i = 0 ; i < 8; ++i) {
            data[i] = s.data[i];
        }

        this->trans = s.trans;
    }

    square operator= (const square &s) {
        for (int i = 0; i < 8; ++i) {
            this->data[i] = s.data[i];
        }
        this->trans = s.trans;

        return *this;
    }
};

square
transA(square const &s) {
    square ret(s);
    for (int i = 0; i < 4; ++i) {
        swap(ret.data[i], ret.data[7-i]);
    }

    ret.trans = 'A';
    return ret;
}

square
transB(square const &s) {
    square ret(s);

    int tmp = ret.data[3];
    for (int i = 3; i > 0; --i) {
         ret.data[i] = ret.data[i-1];
    }
    ret.data[0] = tmp;

    tmp = ret.data[4];
    for (int i = 4; i < 7; ++i) {
        ret.data[i] = ret.data[i+1];
    }
    ret.data[7] = tmp;

    ret.trans = 'B';
    return ret;
}

square
transC(square const &s) {
     square ret(s);

     int tmp = ret.data[1];
     ret.data[1] = ret.data[6];
     ret.data[6] = ret.data[5];
     ret.data[5] = ret.data[2];
     ret.data[2] = tmp;

     ret.trans = 'C';
     return ret;
}

int main() {
    ofstream fout ("msquare.out");
    ifstream fin ("msquare.in");

    square src, dst;
    for (int i = 0; i < 8; ++i) {
        src.data[i] = i+1;
        fin >> dst.data[i];
    }

    map<square, square> visited, cur;

    cur[src] = src;
    visited[src] = src;

    bool found = false;
    while (!found) {
        map<square, square> next;
        for (auto i : cur) {
            square tmp = transA(i.first);
            if (visited.find(tmp) == visited.end()) {
                next[tmp] = i.first;
                visited[tmp] = i.first;
                if (tmp == dst) {
                     found = true;
                     dst = tmp;
                     break;
                }
            }

            tmp = transB(i.first);
            if (visited.find(tmp) == visited.end()) {
                next[tmp] = i.first;
                visited[tmp] = i.first;
                if (tmp == dst) {
                     found = true;
                     dst = tmp;
                     break;
                }
            }

            tmp = transC(i.first);
            if (visited.find(tmp) == visited.end()) {
                next[tmp] = i.first;
                visited[tmp] = i.first;
                if (tmp == dst) {
                     found = true;
                     dst = tmp;
                     break;
                }
            }
        }

        cur.swap(next);
    }

    string ans;
    int cnt = 0;
    while (!(visited[dst] == dst)) {
         ans.push_back(dst.trans);
         dst = visited[dst];
         cnt ++;
    }

    fout << cnt << endl;
    for (int i = ans.size()-1; i >= 0; --i) {
        fout << (char)ans[i];
    }
    fout << endl;

    return 0;
}
