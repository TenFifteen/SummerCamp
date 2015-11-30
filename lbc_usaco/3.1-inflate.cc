/*
ID: libench1
PROG: inflate
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

struct categ {
    int time;
    int point;
    bool operator< (const categ &c) const {
        return (double)point/time > (double)c.point/c.time;
    }
};

struct cat2 {
    int time;
    int point;
    bool operator< (const cat2 &c) const {
        if (point < c.point) return true;
        if (point > c.point) return false;
        return time > c.time;
    }
    cat2(int t, int p) {
        time = t;
        point = p;
    }
    cat2(categ c) {
        time = c.time;
        point = c.point;
    }
};

int main() {
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");

    int m, n;
    fin >> m >> n;
    vector<categ> v(n);
    for (int i = 0;i < n; ++i) {
        fin >> v[i].point >> v[i].time;
    }

    sort(v.begin(),v.end());

    int total = 0, cur = 0;
    map<cat2, int> mm;
    while (m > 0 && cur < n) {
        if (m >= v[cur].time) {
            int num = m / v[cur].time;
            total += num * v[cur].point;
            m -= num * v[cur].time;

            mm[cat2(v[cur])] += num;
            //cout << "add " << v[cur].time << " " << v[cur].point << " " << num << endl;;
        } else {
            bool notFount = true;
            for (auto it = mm.begin(); it != mm.end(); ++it) {
                if (it->first.point >= v[cur].point) {
                    break;
                }

                if (it->first.time + m >= v[cur].time) {
                    //cout << "repalce " << it->first.point << " with " << v[cur].point << endl;
                    mm[cat2(v[cur])]++;
                    mm[it->first]--;

                    total -= it->first.point;
                    total += v[cur].point;

                    m -= v[cur].time;
                    m += it->first.time;

                    if (mm[it->first] == 0) {
                        mm.erase(it->first);
                    }

                    notFount = false;
                    break;
                }
            }

            if (notFount) {
                 cur++;
            }
        }
    }

    fout << total << endl;

    return 0;
}
