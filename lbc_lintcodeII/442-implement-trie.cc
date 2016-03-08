/*
题目大意：
实现一个Trie树。

解题思路：
直接写就行。

遇到的问题：
没有。
*/
/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> next;
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for (auto ch : word) {
            if (cur->next.find(ch) == cur->next.end()) cur->next[ch] = new TrieNode();
            cur = cur->next[ch];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for (auto ch : word) {
            if (cur->next.find(ch) == cur->next.end()) return false;
            cur = cur->next[ch];
        }
        return cur->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (auto ch : prefix) {
            if (cur->next.find(ch) == cur->next.end()) return false;
            cur = cur->next[ch];
        }
        return true;
    }

private:
    TrieNode* root;
};