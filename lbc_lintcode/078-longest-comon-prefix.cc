/*
题目：28 % 最长公共前缀 中等

题目大意：
给定一组字符串，求最长公共前缀

解题思路：
用字典树

遇到的问题：
竟然一次写对了，太感动了。
*/
class Solution {
private:
    class Node{
    public:
        unordered_map<char, Node *> next;
        bool isWord;
        Node(){
            isWord = false;
        }
    };
    Node *head;
    void add(string &word) {
        Node *cur = head;
        for (auto w : word) {
            if (cur->next.count(w) == 0) {
                cur->next[w] = new Node();
            }
            cur = cur->next[w];
        }
        cur->isWord = true;
    }
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        head = new Node();
        for (auto &word : strs) {
            add(word);
        }
        string ans;
        while (head->next.size() == 1 && head->isWord == false) {
            char tmp;
            for (auto ch : head->next) {
                tmp = ch.first;
            }
            ans.push_back(tmp);
            head = head->next[tmp];
        }
        return ans;
    }
};
