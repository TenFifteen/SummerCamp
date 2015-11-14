/*
ID: libench1
PROG: combo
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>

struct Node {
    int x, y, z;
    Node(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    bool operator< (const Node &n) const {
        if (x < n.x) return true;
        if (x > n.x) return false;
        if (y < n.y) return true;
        if (y > n.y) return false;
        if (z < n.z) return true;
        return false;
    }
};

using namespace std;

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");

    int n;
    fin >> n;
    int a,b,c;
    int d,e,f;
    fin >> a >> b >> c;
    fin >> d >> e >> f;

    set<Node> us;

    for (int x = a - 2; x <= a + 2; ++x) {
        for (int y = b - 2; y <= b + 2; ++y) {
            for (int z = c - 2; z <= c + 2; ++z) {
                 int t1 = x;
                 int t2 = y;
                 int t3 = z;

                 if (t1 < 1) {
                     t1 += n;
                 } else if (t1 > n) {
                    t1 -= n;
                 }

                 if (t2 < 1) {
                     t2 += n;
                 } else if (t2 > n) {
                     t2 -= n;
                 }

                 if (t3 < 1) {
                     t3 += n;
                 } else if (t3 > n) {
                     t3 -= n;
                 }

                 us.insert(Node(t1, t2, t3));
            }
        }
    }

    for (int x = d - 2; x <= d + 2; ++x) {
        for (int y = e - 2; y <= e + 2; ++y) {
            for (int z = f - 2; z <= f + 2; ++z) {
                 int t1 = x;
                 int t2 = y;
                 int t3 = z;

                 if (t1 < 1) {
                     t1 += n;
                 } else if (t1 > n) {
                    t1 -= n;
                 }

                 if (t2 < 1) {
                     t2 += n;
                 } else if (t2 > n) {
                     t2 -= n;
                 }

                 if (t3 < 1) {
                     t3 += n;
                 } else if (t3 > n) {
                     t3 -= n;
                 }

                 us.insert(Node(t1, t2, t3));
            }
        }
    }

    if (n <= 3) {
        fout << n*n*n << endl;
    } else {
        fout << us.size() << endl;
    }

    return 0;
}
