#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Given n nodes labeled from 0 to n - 1 and a list of
 *          undirected edges (each edge is a pair of nodes), write
 *          a function to check whether these edges make up a valid tree.
 * Solve: use union and find set.
 * Tips: see comments below
 */
int find(vector<int> &parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, i);
    }

    // return father[i] rather than i
    // because they are not always equal
    return father[i];
}

int uni(vector<int> &parent, vector<int> &rank, int i, int j) {
    int pi = find(parent, i);
    int pj = find(parent, j);

    if (pi != pj) {
        if (rank[pi] == rank[pj]) {
            parent[pj] = pi;
            ++rank[pi];
        } else if(rank[pi] > rank[pj]) {
            parent[pj] = pi;
        } else {
            parent[pi] = pj;
        }
    }
}
/**
 * @param n an integer
 * @param edges a list of undirected edges
 * @return true if it's a valid tree, or false
 */
bool validTree(int n, vector<vector<int> >& edges) {
    // Write your code here
    if (edges.size() != n-1) return false;

    vector<int> parent(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;
    vector<int> rank(n, 0);
    for (int i = 0; i < n-1; ++i) {
        uni(parent, rank, edges[i][0], edges[i][1]);
    }

    // Don't compare parent[i] only, we can't guarantee
    // all the tree has only one level.
    int f = find(parent, 0);
    for (int i = 1; i < n; ++i) {
        if (find(parent, i) != f) return false;
    }

    return true;
}

int main()
{
    vector<vector<int> > ans(4, vector<int>());
    ans[0].push_back(0);
    ans[0].push_back(1);
    ans[1].push_back(0);
    ans[1].push_back(2);
    ans[2].push_back(0);
    ans[2].push_back(3);
    ans[3].push_back(1);
    ans[3].push_back(4);

    validTree(5, ans);

    return 0;
}
