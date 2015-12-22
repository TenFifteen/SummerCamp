/*
题目大意：
给定一个二叉树，设计一个算法将其序列化和反序列化。

解题思路：
直接按照二叉树分层遍历的过程将其存放到字符串中。
并且按照同样的顺序将其反序列化。
见代码。

遇到的问题：
没有问题。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<string> split(string str, char delim) {
        stringstream ss(str);
        vector<string> ans;
        
        string cur;
        while (ss >> cur) {
            ans.push_back(cur);
        }
        
        return ans;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode *> q;
        if (root == NULL) {
            return ans;
        }
        
        q.push(root);
        while (q.size() > 0) {
            TreeNode *root = q.front();
            q.pop();
            
            if (root == NULL) {
                ans.append("n ");
            } else {
                ans.append(to_string(root->val) + " ");
                q.push(root->left);
                q.push(root->right);
            }
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        vector<string> words = split(data, ' ');
        
        TreeNode *root = new TreeNode(stoi(words[0]));
        queue<TreeNode *> q;
        q.push(root);
        
        for (int i = 1; i < words.size(); i += 2) {
            TreeNode *cur = q.front();
            q.pop();
            
            if (words[i][0] != 'n') {
                cur->left = new TreeNode(stoi(words[i]));
                q.push(cur->left);
            }
            if (words[i+1][0] != 'n') {
                cur->right = new TreeNode(stoi(words[i+1]));
                q.push(cur->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));