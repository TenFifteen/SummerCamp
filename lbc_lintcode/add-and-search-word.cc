/*
题目：23 % Add and Search Word 新添加 中等

题目大意：
实现一个trie树

解题思路：
见代码。

遇到的问题：
没有问题。
*/
class WordDictionary {
public:
    struct Node {
        bool isWord;
        unordered_map<char, Node *> next;
        Node() {
            isWord = false;
        }
    };
    
    void _addWord(Node *root, string word) {
        for (auto ch : word) {
            if (root->next.find(ch) == root->next.end()) {
                root->next[ch] = new Node();
            }
            root = root->next[ch];
        }
        root->isWord = true;
    }
    
    bool _search(Node *root, string word) {
        if (word == "") return root->isWord;
        if (word[0] == '.') {
            for (auto n : root->next) {
                if (_search(n.second, word.substr(1, word.size()-1))) {
                    return true;
                }
            }
            return false;
        }
        if (root->next.find(word[0]) != root->next.end()) {
            return _search(root->next[word[0]], word.substr(1, word.size()-1));
        } else {
            return false;
        }
    }
    
    Node *root = new Node();
    
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        _addWord(root, word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        return _search(root, word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
