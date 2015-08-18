/*
题目：二叉树的序列化和反序列化 中等

题目大意：
给定一个二叉树，设计一种序列化方法

解题思路：
按照oj的序列化方法，按照bfs的顺序序列化

遇到的问题：
调试了好久。
*/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        string ans;
        if (root == NULL)return ans;
        vector<TreeNode *> q;
        q.push_back(root);
        while (!q.empty()) {
            vector<TreeNode *> next;
            for (auto n: q) {
                if (n == NULL) {
                    ans.append("#,");
                } else {
                    ans.append(to_string(n->val) + ",");
                    next.push_back(n->left);
                    next.push_back(n->right);
                }
            }
            // while (next.size() > 0 && *next.rbegin() == NULL) next.pop_back();
            // if (next.size() % 2) next.push_back(NULL);
            q.swap(next);
        }
        ans.pop_back();
        return ans;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        if (data == "") return NULL;
        vector<string> split = sub(data);
        auto ret = new TreeNode(stoi(split[0]));
        vector<TreeNode *> cur;
        int index = 1;
        cur.push_back(ret);
        while (cur.size() > 0 && index < split.size()) {
            vector<TreeNode *> next;
            for (int i = 0; i < cur.size(); ++i) {
                if (split[index] != "#") {
                    cur[i]->left = new TreeNode(stoi(split[index++]));
                    next.push_back(cur[i]->left);
                } else {
                    index++;
                }
                if( (split[index] != "#")) {
                    cur[i]->right = new TreeNode(stoi(split[index++]));
                    next.push_back(cur[i]->right);
                } else {
                    index++;
                }
            }
            cur.swap(next);
        }
        return ret;
    }
    vector<string> sub(string data) {
        vector<string> ret;
        int last = 0;
        while (last < data.size()) {
            int end = last+1;
            while (end < data.size() && data[end] != ',')end++;
            ret.push_back(data.substr(last, end-last));
            last = end+1;
        }
        return ret;
    }
};

