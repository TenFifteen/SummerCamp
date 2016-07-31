/*
题目大意：
实现一个trie树

解题思路：
用map记录next信息，再用一个bool变量表示是否形成单词。
每个char的信息直接在map中就可以取到。

遇到的问题：
没有太大问题，以后trie树就按照这样实现了。

再次阅读：
没啥问题，Trie基本也就是这个样子了。
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
        for(auto w:word){
            if(cur->next.count(w) == 0){
                cur->next[w] = new TrieNode();
            }
            cur = cur->next[w];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto cur = root;
        for(auto w:word){
            if(cur->next.count(w) == 0)return false;
            cur = cur->next[w];
        }
        return cur->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto cur = root;
        for(auto w:prefix){
            if(cur->next.count(w) == 0)return false;
            cur = cur->next[w];
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
/*
第二次做：
没有太大问题了。不过就是写的太着急了，有一些小问题。
*/
class TrieNode {
public:
    bool isWord;
    TrieNode* next[26];
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; ++i) {
            next[i] = NULL;
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
        TrieNode *cur = root;
        for (auto ch : word) {
            if (cur->next[ch-'a'] == NULL) {
                cur->next[ch-'a'] = new TrieNode();
            }
            cur = cur->next[ch-'a'];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for (auto ch : word) {
            if (cur->next[ch-'a'] == NULL) return false;
            cur = cur->next[ch-'a'];
        }
        return cur->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (auto ch : prefix) {
            if (cur->next[ch-'a'] == NULL) return false;
            cur = cur->next[ch-'a'];
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
/*
 * good
 */
class TrieNode {
public:
    // Initialize your data structure here.
    bool isWord;
    unordered_map<char, TrieNode *> next;
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
        TrieNode *node = root;
        for (char ch : word) {
            if (node->next.find(ch) == node->next.end()) node->next[ch] = new TrieNode();
            node = node->next[ch];
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
        for (char ch : word) {
            if (node->next.find(ch) == node->next.end()) return false;
            node = node->next[ch];
        }
        return node->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char ch : prefix) {
            if (node->next.find(ch) == node->next.end()) return false;
            node = node->next[ch];
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
