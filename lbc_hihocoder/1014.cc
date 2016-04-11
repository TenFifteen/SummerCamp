#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>

using namespace std;

struct TrieNode {
    int cnt;
    unordered_map<char, TrieNode *> next;
    TrieNode() {
        cnt = 0;
    }
};

void insert(string s, TrieNode *root) {
    root->cnt++;
    if (s == "") return;

    if (root->next.find(s[0]) == root->next.end()) root->next[s[0]] = new TrieNode();
    insert(s.substr(1), root->next[s[0]]);
}

int find(string s, TrieNode *root) {
    for (int i = 0; i < s.size(); ++i) {
        if (root->next.find(s[i]) == root->next.end()) return 0;
        root = root->next[s[i]];
    }
    return root->cnt;
}

int main() {
    TrieNode *root = new TrieNode();

    int n, m;
    cin >> n;
    string input;
    for (int i = 0; i < n; ++i) {
         cin >> input;
         insert(input, root);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
         cin >> input;
         cout << find(input, root) << endl;
    }
    return 0;
}
