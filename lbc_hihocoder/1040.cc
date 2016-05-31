/*
这个题目虽然是做出来了，但是做的过程真是太恶心了。

*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

struct Point {
    int x, y;
    bool operator== (const Point &p) const {
        return x == p.x && y == p.y;
    }
};

struct Line {
    Point p1, p2;
};

bool isCircle(vector<Line> &lines) {
    Point start = lines[0].p1;
    Point next = lines[0].p2;
    for (int i = 1; i < 4; ++i) {
        bool found = false;
        for (int j = i; j < 4; ++j) {
            if (lines[j].p1 == next) {
                found = true;
                swap(lines[j], lines[i]);
                next = lines[i].p2;
                break;
            }
            if (lines[j].p2 == next) {
                found = true;
                swap(lines[j], lines[i]);
                next = lines[i].p1;
                break;
            }
        }
        if (found == false) return false;
    }

    return next == start;
}

double getSlope(const Line &line) {
    if (line.p1.x == line.p2.x) return INT_MAX;
    double ans = line.p1.y-line.p2.y;
    return ans/(line.p1.x-line.p2.x);
}

bool isParallel(vector<Line> &lines) {
    return abs(getSlope(lines[0]) - getSlope(lines[2])) < 0.001
        && abs(getSlope(lines[1]) - getSlope(lines[3])) < 0.001;
}

bool isVertical(vector<Line> &lines) {
    if (lines[0].p1.x == lines[0].p2.x) {
        return lines[1].p1.y == lines[1].p2.y;
    }
    if (lines[1].p1.x == lines[1].p2.x) {
        return lines[0].p1.y == lines[0].p2.y;
    }
    return abs(getSlope(lines[0])*getSlope(lines[1]) + 1.0) < 0.001;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<Line> lines(4);
        for (int i = 0; i < 4; ++i) {
            cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
        }
        if (isCircle(lines) && isParallel(lines) && isVertical(lines)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
