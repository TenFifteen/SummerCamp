#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Cmp {
    bool operator() (const vector<int> p1, const vector<int> p2) const {
        if (p1[0] > p2[0]) return true;
        else if (p1[0] < p2[0]) return false;
        else return p1[2] > p2[2];
    }
};

/**
 * @param buildings: A list of lists of integers
 * @return: Find the outline of those buildings
 */
vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
    int n = buildings.size();
    if (n <= 1) return buildings;

    priority_queue<vector<int>, vector<vector<int> >, Cmp> heap;
    for (int i = 0; i < n; ++i) heap.push(buildings[i]);

    vector<vector<int> > ans;
    vector<int> it = heap.top();
    heap.pop();

    while (!heap.empty()) {
        vector<int> now = heap.top();
        heap.pop();

        if (now[0] > it[1]) {
            ans.push_back(it);
            it = now;
        } else if(now[1] < it[1]){
            if (now[2] > it[2]) {
                // cut the leading piece
                vector<int> tmp(it);
                tmp[1] = now[0];
                ans.push_back(tmp);

                // push back the left piece if have
                if (it[1] != now[1]) {
                    it[0] = now[1];
                    heap.push(it);
                }

                // iterator
                it = now;
            }
        } else {
            if (now[2] == it[2]) {
                it[1] = now[1];
            } else if (now[2] > it[2] || now[0] == it[1]) {
                it[1] = now[0];
                ans.push_back(it);
                it = now;
            } else {
                if (now[1] > it[1]) {
                    now[0] = it[1];
                    heap.push(now);
                }
            }
        }
    }
    ans.push_back(it);

    return ans;
}

int main()
{
    vector<vector<int> > input;
    vector<int> tmp(3, 0);
    tmp[0] = 1;
    tmp[1] = 10;
    tmp[2] = 3;
    input.push_back(tmp);
    tmp[0] = 2;
    tmp[1] = 5;
    tmp[2] = 3;
    input.push_back(tmp);
    tmp[0] = 5;
    tmp[1] = 6;
    tmp[2] = 1;
    input.push_back(tmp);

    vector<vector<int> > ans = buildingOutline(input);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
