/**
 * Problem: save and query.
 * Solve: hash map
 * Tips: no
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unordered_map<string, int> cnt;
    int n, q;
    cin >> n;
    while (n--) {
        string tmp;
        cin >> tmp;
        cnt[tmp]++;
    }

    cin >> q;
    while (q--) {
        string tmp;
        cin >> tmp;
        cout << cnt[tmp] << endl;
    }

    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    public:
        string val;
        int cnt;
        Node *next;

        Node(string v) {
            val = v;
            cnt = 1;
            next = NULL;
        }
};

int hashCode(const string &s, int n){
    int len = s.size();
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        ans = (ans << 1) ^(s[i]);
    }

    return ans % n;
}

void insert(vector<Node*> &htable, string &s, int n) {
    int c = hashCode(s, n);
    Node *h = htable[c];

    while (h) {
        if (h->val == s) {
            h->cnt++;
            return;
        }
        h = h->next;
    }

    Node *now = new Node(s);
    now->next = htable[c];
    htable[c] = now;
}

int count(vector<Node*> &htable, string &s, int n) {
    int c = hashCode(s, n);
    Node *h = htable[c];

    while (h) {
        if (h->val == s) return h->cnt;
        h = h->next;
    }
    return 0;
}

void release(vector<Node*> &htable, int n) {
    for (int i = 0; i < n; ++i) {
        Node *h = htable[i];
        while (h) {
            Node *now = htable[i];
            h = h->next;
            delete now;
        }
    }
}
int main() {
    int n, q;
    cin >> n;

    int total = 2 * n + 1;
    vector<Node*> hashTable(total, NULL);

    string tmp;
    while (n--) {
        cin >> tmp;
        insert(hashTable, tmp, total);
    }

    cin >> q;
    while (q--) {
        cin >> tmp;
        cout << count(hashTable, tmp, total) << endl;
    }

    release(hashTable, total);
    return 0;
}

