/*
ID: libench1
PROG: milk2
LANG: C++11
*/
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n;
    vector<pair<int, int> > intervals;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        int left, right;
        fin >> left >> right;
        intervals.push_back(make_pair(left, right));
    }

    sort(intervals.begin(), intervals.end());

    vector<pair<int, int> > merge;
    merge.push_back(intervals[0]);
    for (int i = 1; i < n; ++i) {
        if (intervals[i].first > merge[merge.size()-1].second) {
            merge.push_back(intervals[i]);
        } else {
            merge[merge.size()-1].second = max(merge[merge.size()-1].second, intervals[i].second);
        }
    }

    int yes = 0, no = 0;
    for (auto m : merge) {
        if (m.second - m.first > yes) {
            yes = m.second - m.first;
        }
    }

    if (merge.size() > 1) {
        for (int i = 1; i < merge.size(); ++i) {
            if (merge[i].first - merge[i-1].second > no) {
                no = merge[i].first - merge[i-1].second;
            }
        }
    }

    fout << yes << " " << no << endl;

    return 0;
}
