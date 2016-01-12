#include <iostream>
#include <vector>
#include <string>

using namespace std;
/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
    public:
        // Initialize your data structure here.
        TrieNode* children[26];
        bool end;

        TrieNode() {
            for (int i = 0; i < 26; ++i) children[i] = NULL;
            end = false;
        }
};

/**
 * Problem: Implement a trie tree with insert, search, and startsWith.
 * Solve: 26 pointers and 'end' flag.
 * Tips: no
 */
class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }

        // Inserts a word into the trie.
        void insert(string word) {
            int n = word.size();
            TrieNode *level = root;
            for (int i = 0; i < n; ++i) {
                int pos = word[i] - 'a';
                if (level->children[pos] == NULL) {
                    level->children[pos] = new TrieNode();
                }
                level = level->children[pos];
            }
            level->end = true;
        }

        // Returns if the word is in the trie.
        bool search(string word) {
            int n = word.size();
            TrieNode *level = root;
            for (int i = 0; i < n; ++i) {
                int pos = word[i] - 'a';
                if (level->children[pos] == NULL) {
                    return false;
                }
                level = level->children[pos];
            }
            return level->end == true;
        }

        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix) {
            int n = prefix.size();
            TrieNode *level = root;
            for (int i = 0; i < n; ++i) {
                int pos = prefix[i] - 'a';
                if (level->children[pos] == NULL) {
                    return false;
                }
                level = level->children[pos];
            }
            return level != NULL;
        }

    private:
        TrieNode* root;
};

int main()
{
    Trie trie;
    trie.insert("lintcode");
    cout << trie.search("lint") << endl;
    cout << trie.startsWith("lint") << endl;
}
