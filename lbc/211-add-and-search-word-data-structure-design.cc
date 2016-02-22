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