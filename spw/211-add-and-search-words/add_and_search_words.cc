#include <iostream>
#include <string>

using namespace std;

class TrieNode{
    public:
        TrieNode *nodes[26];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; ++i) {
                nodes[i] = NULL;
            }
        }
};

/**
 * Problem: Design a data structure that supports the following two operations:
 *          add and search.
 * Solve: 1. Tire
 *        2. DFS
 * Tips: substr
 */
class WordDictionary {
    private:
        TrieNode *root;

        bool dfs(TrieNode *root, string word) {
            if (root == NULL) return false;

            TrieNode *it = root;
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] == '.') {
                    // warning: should be i+1
                    string right = word.substr(i+1);
                    for (int j = 0; j < 26; ++j) {
                        if (it->nodes[j] && dfs(it->nodes[j], right)) return true;
                    }
                    return false;
                } else {
                    int pos = word[i] - 'a';
                    if (it->nodes[pos]) {
                        it = it->nodes[pos];
                    } else {
                        return false;
                    }
                }
            }

            return it->isEnd;
        }

    public:
        WordDictionary() {
            root = new TrieNode();
        }

        // Adds a word into the data structure.
        void addWord(string word) {
            TrieNode *pre = root;
            for (int i = 0; i < word.size(); ++i) {
                int pos = word[i] - 'a';
                if (pre->nodes[pos] == NULL)
                    pre->nodes[pos] = new TrieNode();
                pre = pre->nodes[pos];
            }
            pre->isEnd = true;
        }

        // Returns if the word is in the data structure. A word could
        // contain the dot character '.' to represent any one letter.
        bool search(string word) {
            return dfs(root, word);
        }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main() {
    WordDictionary wd;
    wd.addWord("ab");
    wd.search("a.");

    return 0;
}

class TrieNode {
public:
    TrieNode *next[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; ++i)
            next[i] = NULL;
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *it = root;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            int pos = word[i] - 'a';
            if (it->next[pos] == NULL)
                it->next[pos] = new TrieNode();
            it = it->next[pos];
        }
        it->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(TrieNode *now, string &word, int i) {
        if (now == NULL) return false;
        if (i == word.size())
            return now->isEnd;

        if (word[i] == '.') {
            for (int j = 0; j < 26; ++j)
                if (now->next[j] && dfs(now->next[j], word, i+1))
                    return true;
            return false;
        } else {
            int pos = word[i] - 'a';
            return dfs(now->next[pos], word, i+1);
        }
    }
};
