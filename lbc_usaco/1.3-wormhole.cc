/*
ID: libench1
PROG: wormhole
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

unordered_map<int, int> buildLink(vector<pair<int, int> > &hole) {
    map<pair<int, int>, int> mmap;
    for (int i = 0; i < hole.size(); ++i) {
        mmap[hole[i]] = i;
    }

    unordered_map<int, vector<int> > um;
    for (auto h : hole) {
        um[h.second].push_back(h.first);
    }

    unordered_map<int, int> ret;
    for (auto u: um) {
        if (u.second.size() > 1) {
            sort(u.second.begin(), u.second.end());
            for (int i = 1; i < u.second.size(); ++i) {
                ret[mmap[make_pair(u.second[i-1], u.first)]] = mmap[make_pair(u.second[i], u.first)];
            }
        }
    }

    return ret;
}

bool isInf(vector<pair<int, int> > &hole, unordered_map<int, int> &um, unordered_map<int, int> &link) {
    for (int start = 0; start < hole.size(); ++start) {
        unordered_set<int> us;
        us.insert(start);

        int cur = um[start];
        bool inf = false;
        while (1) {
            if (link.find(cur) == link.end()) {
                break;
            }
            if (us.find(link[cur]) != us.end()) {
                inf = true;
                break;
            }
            us.insert(link[cur]);

            cur = um[link[cur]];
        }

        if (inf == true) {
            //cout << "start = " << start << endl;
            return true;
        }
    }

    return false;
}

int search(vector<pair<int, int> > &hole, vector<int> &flag, unordered_map<int, int> &um, unordered_map<int, int> &link) {
    if (um.size() == hole.size()) {
        if (isInf(hole, um, link)) {
            //cout << "----------------------------" << endl;
            //for (auto i : um) {
            //    cout << i.first << "->" << i.second << endl;
            //}
            return 1;
        }
        return 0;
    }

    int first = -1;
    for (int i = 0; i < hole.size(); ++i) {
        if (flag[i] == false) {
            first = i;
            flag[i] = true;
            break;
        }
    }

    int ret = 0;
    for (int i = first+1; i < hole.size(); ++i) {
        if (flag[i] == false) {
            flag[i] = true;
            um[i] = first;
            um[first] = i;
            ret += search(hole, flag, um, link);
            flag[i] = false;
            um.erase(first);
            um.erase(i);
        }
    }

    flag[first] = false;

    return ret;
}

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");

    int n;
    fin >> n;
    vector<pair<int, int> > hole;
    for (int i = 0; i < n; ++i) {
        int a, b;
        fin >> a >> b;
        hole.push_back(make_pair(a, b));
    }

    unordered_map<int, int> link = buildLink(hole);
    vector<int> flag(hole.size(), false);
    unordered_map<int, int> um;

    //cout << "link--------------------" << endl;
    //for (auto i : link) {
    //    cout << i.first << "->" << i.second << endl;
    //}

    fout << search(hole, flag, um, link) << endl;

    return 0;
}
