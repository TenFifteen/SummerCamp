/*
题目大意：
实现一个trie树，其查询可以有.通配

解题思路：
遇到通配符，就递归查找所有子树

遇到的问题：
一开始实现的是完全递归，超时。
现在是只遇到通配符才递归。

再次阅读：
就是用一棵trie树，但是用的时候需要注意通配符的情况需要进行递归。
*/
class WordDictionary {
private:
    struct Node{
        unordered_map<char, Node*> next;
        bool isWord;
        Node(){
            isWord = false;
        }
    };

    bool find(string word, Node *cur) {
        if(word == ""){
            return cur->isWord;
        }
        for(int i = 0; i < word.size(); ++i){
            if(word[i] != '.'){
                if(cur->next.count(word[i]) == 0)return false;
                cur = cur->next[word[i]];
            }else{
                for(auto n:cur->next){
                    if(find(word.substr(i+1, word.size()-1-i), n.second))return true;
                }
                return false;
            }
        }
        return cur->isWord;
    }

    Node *root;
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        auto cur = root;
        for(auto w:word){
            if(cur->next.count(w) == 0){
                cur->next[w] = new Node();
            }
            cur = cur->next[w];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word == ""){
            return root->isWord;
        }
        auto cur = root;
        for(int i = 0; i < word.size(); ++i){
            if(word[i] != '.'){
                if(cur->next.count(word[i]) == 0)return false;
                cur = cur->next[word[i]];
            }else{
                for(auto n:cur->next){
                    if(find(word.substr(i+1, word.size()-1-i), n.second))return true;
                }
                return false;
            }
        }
        return cur->isWord;
    }

    WordDictionary(){
        root = new Node();
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
/*
第二次做：
这次一开始没有看到有通配符。
结果后边写递归的时候竟然错了一些小地方。
*/
class WordDictionary {
private:
    struct TrieNode {
        bool isWord;
        TrieNode* next[26];
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; ++i) next[i] = NULL;
        }
    };

    TrieNode *root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        cout << "add " << word << endl;
        TrieNode *cur = root;
        for (auto ch : word) {
            if (cur->next[ch-'a'] == NULL) {
                cur->next[ch-'a'] = new TrieNode();
            }
            cur = cur->next[ch-'a'];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        cout << "search " << word << endl;
        return innerSearch(word, root);
    }

    bool innerSearch(string word, TrieNode *r) {
        TrieNode *cur = r;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; ++j) {
                    if (cur->next[j] != NULL && innerSearch(word.substr(i+1), cur->next[j])) return true;
                }
                return false;
            }
            if (cur->next[word[i]-'a'] == NULL) return false;
            cur = cur->next[word[i]-'a'];
        }
        return cur->isWord;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
/*
 * ok
 */
class WordDictionary {
private:
    struct Node {
        bool isWord;
        unordered_map<char, Node *> next;
        Node() : isWord(false) {}
    };

    Node *root;

    bool search(string word, Node *node) {
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (auto p : node->next) {
                    if (search(word.substr(i+1), p.second)) return true;
                }
                return false; // corner case.
            } else if (node->next.find(word[i]) == node->next.end()) {
                return false;
            }
            node = node->next[word[i]];
        }
        return node->isWord;
    }

public:

    WordDictionary() {
        root = new Node();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        Node *node = root;
        for (auto ch : word) {
            if (node->next.find(ch) == node->next.end()) node->next[ch] = new Node();
            node = node->next[ch];
        }
        node->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
