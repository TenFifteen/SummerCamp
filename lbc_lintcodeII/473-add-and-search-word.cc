/*
题目大意：
设计一个单词的查找数据结构。

解题思路：
trie树

遇到的问题：
没有。
*/
class WordDictionary {
    class TrieNode {
    public:
        bool isWord;
        unordered_map<char, TrieNode*> next;
        TrieNode() {
            isWord = false;
        }
    };
    
    TrieNode *root;
    
    bool find(string word, TrieNode *node) {
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (auto n : node->next) {
                    if (find(word.substr(i+1), n.second)) return true;
                }
                return false;
            }
            if (node->next.find(word[i]) == node->next.end()) return false;
            node = node->next[word[i]];
        }
        
        return node->isWord;
    }
    
public:
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        TrieNode *cur = root;
        for (auto ch : word) {
            if (cur->next.find(ch) == cur->next.end())
                cur->next[ch] = new TrieNode();
            cur = cur->next[ch];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        return find(word, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");