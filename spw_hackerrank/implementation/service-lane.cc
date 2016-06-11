/**
 * Problem: find the minimum number in the vector interval.
 * Solve: segment treee
 * Tips: no
 */
#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class SegNode {
    public:
        SegNode *left, *right;
        int start, end, val;

        SegNode(int s, int e, int v) {
            start = s, end = e, val = v;
            left = right = NULL;
        }
};

SegNode* buildTree(vector<int> &wid, int start, int end) {
    if (start > end) return NULL;
    if (start == end)
        return new SegNode(start, end, wid[start]);

    SegNode *root = new SegNode(start, end,  wid[start]);
    int mid = (start + end) /  2;
    root->left = buildTree(wid, start, mid);
    root->right = buildTree(wid, mid+1, end);
    root->val = min(root->left == NULL ? INT_MAX : root->left->val,
            root->right == NULL ? INT_MAX : root->right->val);
    return root;
}

int findMin(SegNode *root, int start, int end) {
    if (root == NULL) return INT_MAX;
    if (root->start == start && root->end == end) return root->val;

    int mid = (root->start + root->end) / 2;
    if (end <= mid) return findMin(root->left, start, end);
    else if (start > mid) return findMin(root->right, start, end);
    else return min(findMin(root->left, start, mid), findMin(root->right, mid+1, end));
}

void delTree(SegNode *root) {
    if (root == NULL) return;

    delTree(root->left);
    delTree(root->right);
    delete root;
}

int main(){
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0;width_i < n;width_i++){
        cin >> width[width_i];
    }

    SegNode *root = buildTree(width, 0, n-1);
    while (t--) {
        int i, j;
        cin >> i >> j;
        cout << findMin(root, i, j) << endl;
    }
    delTree(root);
    return 0;
}

