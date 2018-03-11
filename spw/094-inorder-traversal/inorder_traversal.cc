#include <cstdio>
#include <vector>
#include <stack>

using namespace std;
/**
 ** Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(vector<int> &ans, TreeNode *root) {
    if (!root) return;

    traverse(ans, root->left);
    ans.push_back(root->val);
    traverse(ans, root->right);
}

/**
 * Problem: binary tree inorder traversal
 * Solve: recursion
 * Tips: see below
 */
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    traverse(ans, root);
    return ans;
}

vector<int> non_recur(vector<int> &ans, TreeNode* root) {
    stack<TreeNode *> nodes;

    TreeNode* node = root;
    // the node is not in the stack at first
    while (node || !nodes.empty()) {
        while (node) {
            nodes.push(node);
            node = node->left;
        }
        node = nodes.top();
        nodes.pop();
        // visit when pop it
        ans.push_back(node->val);

        node = node->right;
    }
    return ans;
}

class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            stack<TreeNode*> s;

            vector<int> ans;
            while (!s.empty() || root) {
                while (root) {
                    s.push(root);
                    root = root->left;
                }

                TreeNode *now = s.top();
                s.pop();
                ans.push_back(now->val);
                root = now->right;
            }

            return ans;
        }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Morris inorder traversal
/*
   1. Initialize current as root
   2. While current is not NULL
   If current does not have left child
   a) Print current’s data
   b) Go to the right, i.e., current = current->right
   Else
   a) Make current as right child of the rightmost
   node in current's left subtree
   b) Go to this left child, i.e., current = current->left
   */
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;

            TreeNode* current = root;
            while (current != NULL) {
                if (current->left == NULL) {
                    ans.push_back(current->val);
                    current = current->right;
                } else {
                    // find the rightmost node of the left child
                    TreeNode* prev = current->left;
                    while (prev->right != NULL && prev->right != current) {
                        prev = prev->right;
                    }

                    // first traverse the root
                    if (prev->right == NULL) {
                        prev->right = current;
                        current = current->left;
                        // second traverse the root, back from the
                    } else if (prev->right == current) {
                        ans.push_back(current->val);
                        current = current->right;
                        prev->right = NULL;
                    }
                }
            }

            return ans;
        }
};
