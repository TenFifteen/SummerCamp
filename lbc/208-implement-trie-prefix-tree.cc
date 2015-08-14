/*
题目大意：
实现一个trie树

解题思路：
用map记录next信息，再用一个bool变量表示是否形成单词。
每个char的信息直接在map中就可以取到。

遇到的问题：
没有太大问题，以后trie树就按照这样实现了。
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