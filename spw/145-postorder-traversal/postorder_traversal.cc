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
