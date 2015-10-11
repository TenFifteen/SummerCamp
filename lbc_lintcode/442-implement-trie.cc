/*
题目：27 % Implement Trie 中等

题目大意：
实现一个trie树

解题思路：
见代码

遇到的问题：
没有问题。
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
    unordered_map<char, TrieNode *> next;
    bool isWord;
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
        auto cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->next.find(word[i]) == cur->next.end()) {
                cur->next[word[i]] = new TrieNode();
            }
            cur = cur->next[word[i]];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->next.find(word[i]) == cur->next.end()) return false;
            cur = cur->next[word[i]];
        }
        return cur->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto cur = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (cur->next.find(prefix[i]) == cur->next.end()) return false;
            cur = cur->next[prefix[i]];
        }
        return true;
    }

private:
    TrieNode* root;
};
