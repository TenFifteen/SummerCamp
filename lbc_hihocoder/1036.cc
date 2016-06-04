/*
这就是传说中的AC自动机吧！！！
竟然按照提示写出来了，虽然写的时间有点长。尤其是有一个小问题没有注意到。。
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

const int maxm = 1000003;
char input[maxm];

struct Node {
    Node *fa;
    Node *next[26];
    bool isWord;
    Node() {
        fa = NULL;
        for (int i = 0; i < 26; ++i) next[i] = NULL;
        isWord = false;
    }
};

void insert(Node *root) {
    char *word = input;
    int len = strlen(input);
    for (int i = 0; i < len; ++i) {
        int index = word[i]-'a';
        if (root->next[index] == NULL) root->next[index] = new Node();
        root = root->next[index];
    }
    root->isWord = true;
}

void buildAC(Node *root) {
    Node *realRoot = root;

    root->fa = root;
    queue<Node *> q;
    queue<Node *> father;
    queue<int> edge;
    for (int i = 0; i < 26; ++i) {
        if (root->next[i] == NULL) root->next[i] = root;
        else {
            q.push(root->next[i]);
            father.push(root);
            edge.push(i);
        }
    }

    while (q.size() > 0) {
        Node *cur = q.front();
        Node *cur_fa = father.front();
        int index = edge.front();
        q.pop(), father.pop(), edge.pop();

        if (cur_fa == realRoot) cur->fa = realRoot; // second layer's node's fa is root.
        else cur->fa = cur_fa->fa->next[index];
        for (int i = 0; i < 26; ++i) {
            if (cur->next[i] == NULL) {
                cur->next[i] = cur->fa->next[i];
            } else {
                q.push(cur->next[i]);
                father.push(cur);
                edge.push(i);
            }
        }
    }
}

bool find_str(Node *root) {
    char *str = input;
    int len = strlen(input);
    for (int i = 0; i < len; ++i) {
        root = root->next[str[i]-'a'];
        if (root->isWord) return true;
    }
    return false;
}


int main() {
    int n;
    scanf("%d", &n);
    Node *root = new Node();
    for (int i = 0; i < n; ++i) {
        scanf("%s", input);
        insert(root);
    }

    buildAC(root);

    scanf("%s", input);

    if (find_str(root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
