/*
一开始用的线段树，结果各种超时。最后无奈只能换成bit了。
另外，用merge sort的思路可能是最接近出题者想要的答案。。。
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 20000002;
int bit[maxn];

void init() {
    memset(bit, 0, sizeof(bit));
}

int get(int val) {
    int ret = 0;
    while (val) {
        ret += bit[val];
        val -= (val & -val);
    }
    return ret;
}

void set(int val) {
    while (val < maxn) {
        bit[val]++;
        val += (val & -val);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        int n;
        long long total = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int num;
            scanf("%d", &num);
            num += 10000001;
            total += (i - get(num));
            set(num);
        }
        cout << total << endl;
    }
    return 0;
}

/* first version of segment tree resolution. timeout for last three test cases.
struct Node {
    int start, end, cnt;
    Node *left, *right;
    Node(int s, int e): start(s), end(e), cnt(0), left(NULL), right(NULL) {}
};

void insert(Node *root, int val) {
    if (root->start > val || root->end < val) return;
    if (root->start == root->end) {
        root->cnt++;
        return;
    }
    
    int mid = (root->start + root->end) / 2;
    if (root->left == NULL) root->left = new Node(root->start, mid);
    if (root->right == NULL) root->right = new Node(mid+1, root->end);
    if (val > mid) insert(root->right, val);
    else insert(root->left, val);
    root->cnt++;
}

int getCount(Node *root, int L, int R) {
    if (root == NULL || root->end < L || root->start > R) return 0;
    if (root->start >= L && root->end <= R) return root->cnt;
    return getCount(root->left, L, R) + getCount(root->right, L, R);
}

void destroy(Node *root) {
    if (root == NULL) return;
    destroy(root->left);
    destroy(root->right);
    root->cnt = 0;
}

int main() {
    int T;
    scanf("%d", &T);
    Node *root = new Node(-10000002, 10000002);
    while (T--) {
        int n;
        long long total = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int num;
            scanf("%d", &num);
            total += getCount(root, num+1, 10000002);
            insert(root, num);
        }
        cout << total << endl;
        destroy(root);
    }
    return 0;
}
*/
