/**
 * Problem: Design a data structure that supports the following two operations: addWord(word) and search(word)
 *          search(word) can search a literal word or a regular expression string containing only letters a-z or ..
 *          A . means it can represent any one letter.
 * Solve: Trie + dfs
 * Tips: Too many details, see below.
 */
class TrieNode{
    public:
        TrieNode *nodes[26];
        bool isEnd;

        TrieNode() {
            for(int i = 0; i < 26; ++i) nodes[i] = NULL;
            isEnd = false;
        }
};

class WordDictionary {
    private:
        TrieNode *root;
        bool searchNode(TrieNode *root, string word) {
            if (root == NULL) return false;

            TrieNode *it = root;
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] == '.') {
                    string suffix = word.substr(i+1);
                    for (int j = 0; j < 26; ++j) {
                        if (it->nodes[j]) {
                            if (searchNode(it->nodes[j], suffix)) return true;
                        }
                    }
                    // mind the position, don't put it in the loop above.
                    return false;
                } else {
                    int pos = word[i] - 'a';
                    it = it->nodes[pos];
                    // because we don't recursive here, then we should judge the
                    // it here
                    if (it == NULL) return false;
                }
            }

            return it->isEnd == true;
        }
    public:
        WordDictionary() {
            root = new TrieNode();
        }

        // Adds a word into the data structure.
        void addWord(string word) {
            TrieNode *it = root;
            for (int i = 0; i < word.size(); ++i) {
                int pos = word[i] - 'a';
                if (it->nodes[pos] == NULL) {
                    it->nodes[pos] = new TrieNode();
                }

                it = it->nodes[pos];
            }
            it->isEnd = true;
        }

        // Returns if the word is in the data structure. A word could
        // contain the dot character '.' to represent any one letter.
        bool search(string word) {
            return searchNode(root, word);
        }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
