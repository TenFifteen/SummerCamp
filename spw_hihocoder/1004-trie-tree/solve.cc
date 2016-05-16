/**
 * Problem: implement a prefix query tree.
 * Solve: use trie tree.
 * Tips: when to store the count.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode *nodes[26];
    int count;

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            nodes[i] = NULL;
        count = 0;
    }
};

class Trie {
private:
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        freeNodes(root);
    }

    void freeNodes(TrieNode *root) {
        if (root == NULL) return;

        for (int i = 0; i < 26; ++i) {
            freeNodes(root->nodes[i]);
        }
        delete root;
    }

    void addWord(string word) {
        int n = word.size();
        if (n == 0) return;

        TrieNode *it = root;
        for (int i = 0; i < n; ++i) {
            int pos = word[i] - 'a';

            if (it->nodes[pos] == NULL) {
                it->nodes[pos] = new TrieNode();
            }
            it = it->nodes[pos];
            it->count++;
        }

    }

    int countPrefix(string pre) {
        int n = pre.size();
        if (n == 0) return 0;

        TrieNode* it = root;
        for (int i = 0; i < n; ++i) {
            int pos = pre[i] - 'a';

            it = it->nodes[pos];
            if (it == NULL) return 0;
        }

        return it->count;
    }
};



int main()
{
    int n, m;
    Trie dict;

    cin >> n;
    string word;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        dict.addWord(word);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> word;
        cout << dict.countPrefix(word) << endl;
    }

    return 0;
}
