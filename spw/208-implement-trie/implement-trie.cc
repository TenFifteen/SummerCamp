/**
 * Problem: Implement a trie with insert, search and
 *          startswith methods.
 * Sovle: Use two fields: 26 branches and a leaf label.
 * Tips: When insert, create a new node only if that
 *       branch does not exist.
 */
class TrieNode {
    public:
        TrieNode *nodes[26];
        bool isEnd;
        // Initialize your data structure here.
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; ++i) {
                nodes[i] = NULL;
            }
        }
};

class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }

        // Inserts a word into the trie.
        void insert(string word) {
            TrieNode *pre = root;
            for (int i = 0; i < word.length(); ++i) {
                int pos = word[i] - 'a';
                if (pre->nodes[pos] == NULL) {
                    TrieNode *node = new TrieNode();
                    pre->nodes[pos] = node;
                }
                pre = pre->nodes[pos];
            }
            pre->isEnd = true;
        }

        // Returns if the word is in the trie.
        bool search(string word) {
            TrieNode *it = root;
            for (int i = 0; i < word.length(); ++i) {
                int pos = word[i] - 'a';
                if (it->nodes[pos]) {
                    it = it->nodes[pos];
                } else {
                    return false;
                }
            }
            return it->isEnd;
        }

        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix) {
            TrieNode *it = root;
            for (int i = 0; i < prefix.length(); ++i) {
                int pos = prefix[i] - 'a';
                if (it->nodes[pos]) {
                    it = it->nodes[pos];
                } else {
                    return false;
                }
            }
            return true;
        }

    private:
        TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
//
//
class TrieNode {
public:
    TrieNode *next[26];
    bool isEnd;

    // Initialize your data structure here.
    TrieNode() {
        for (int i = 0; i < 26; ++i) next[i] = NULL;
        isEnd = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
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

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *it = root;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            int pos = word[i] - 'a';
            if (it->next[pos] == NULL)
                return false;
            it = it->next[pos];
        }
        return it->isEnd == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *it = root;
        int n = prefix.size();
        for (int i = 0; i < n; ++i) {
            int pos = prefix[i] - 'a';
            if (it->next[pos] == NULL)
                return false;
            it = it->next[pos];
        }
        return true;
    }

private:
    TrieNode* root;
};

