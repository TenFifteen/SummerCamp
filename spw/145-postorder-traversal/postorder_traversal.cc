/**
 * Problem: binary tree post order traversal.
 * Solve: use a pre pointer to judge.
 * Tips: see comments below.
 */
/* struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            stack<TreeNode*> s;

            TreeNode *pre = NULL;
            while (root || !s.empty()) {
                // if root == NULL, we must return from left or right
                // left: we go dive into left in the other brach
                // right: we assign root to NULL when we return from
                // the right.
                //
                // Then we use a pre to judge where we return from.
                // Then we only need to save pre when we pop a element
                // this is the only place we may return from the right.
                if (root == NULL) {
                    root = s.top();
                    // don't forget judge the null
                    if (root->right == NULL || root->right == pre) {
                        ans.push_back(root->val);
                        s.pop();
                        pre = root;
                        root = NULL;
                    } else {
                        root = root->right;
                    }
                } else {
                    s.push(root);
                    root = root->left;
                }
            }

            return ans;
        }
};

class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            stack<TreeNode*> post, prev;

            vector<int> ans;
            if (root) prev.push(root);

            while (!prev.empty()) {
                TreeNode* now = prev.top();
                prev.pop();

                post.push(now);
                if (now->left) prev.push(now->left);
                if (now->right) prev.push(now->right);
            }

            while (!post.empty()) {
                ans.push_back(post.top()->val);
                post.pop();
            }

            return ans;
        }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* current = root, *prev = NULL;

        vector<int> ans;
        while (current || !s.empty()) {
            while (current) {
                s.push(current);
                current = current->left;
            }

            TreeNode* now = s.top();
            if (now->right == NULL || now->right == prev) {
                ans.push_back(now->val);
                prev = now;
                s.pop();
                // get back from the right sub tree
                current = NULL;
            } else {
                // get back from the left sub tree
                current = now->right;
            }
        }

        return ans;
    }
};
