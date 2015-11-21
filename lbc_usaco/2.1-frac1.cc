/*
ID: libench1
PROG: frac1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int gcd(int, int);
struct Node;
Node make_node(int, int);


struct Node {
    int a, b;
    bool operator< (const Node &n) const {
        double self = (double)a/b;
        double it = (double)n.a/n.b;
        return self < it;
    }
};

int gcd(int x, int y) {
    if (x > y) {
        return gcd(y, x);
    }
    if (x == 0) {
        return y;
    }
    return gcd(y%x, x);
}

Node make_node(int a, int b) {
    int g = gcd(a, b);
    Node ret;
    ret.a = a/g;
    ret.b = b/g;
    return ret;
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");

    int n;
    fin >> n;

    set<Node> s;
    s.insert(make_node(0, 1));
    s.insert(make_node(1, 1));
    for (int a = 1; a < n; ++a) {
        for (int b = a+1; b <= n; ++b) {
            s.insert(make_node(a, b));
        }
    }

    for (auto i : s) {
        fout << i.a << "/" << i.b << endl;
    }

    return 0;
}
