/*
题目大意：
对二叉树进行序列化和反序列化

解题思路：
先序遍历

遇到的问题：
没有。
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
    #define isDigit(ch) ((ch) >= '0' && (ch) <= '9')
    
    TreeNode *des(const string &data, int &index) {
        if (index >= data.size() || data[index] == '#') {
            index += 2;
            return NULL;
        }
        
        int front = index;
        while (front < data.size() && isDigit(data[front])) front++;
        
        TreeNode *root = new TreeNode(stoi(data.substr(index, front-index)));
        index = front+1;
        root->left = des(data, index);
        root->right = des(data, index);
        
        return root;
    }
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        if (root == NULL) return "#";
        return to_string(root->val)
               + "," + serialize(root->left)
               + "," + serialize(root->right);
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
        int index = 0;
        return des(data, index);
    }
};
