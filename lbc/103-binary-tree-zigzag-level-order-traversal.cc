/*
题目大意：
与102类似，不过是从左往右一层，从右往左一层。

解题思路：
递归，注意左右顺序。

遇到的问题：
没问题。
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        vector<TreeNode *> v;
        v.push_back(root);
        sub(ans, v, true);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<TreeNode *> v, bool left_to_right){
        vector<TreeNode *> next;
        vector<int> ret;
        if(left_to_right){
            for(int i = 0; i < v.size(); ++i){
                ret.push_back(v[i]->val);
                if(v[i]->left != NULL)next.push_back(v[i]->left);
                if(v[i]->right != NULL)next.push_back(v[i]->right);
            }
        }else{
            for(int i = v.size()-1; i >= 0; --i){
                ret.push_back(v[i]->val);
                if(v[i]->right != NULL)next.push_back(v[i]->right);
                if(v[i]->left != NULL)next.push_back(v[i]->left);
            }
            for(int i = 0; i < next.size()/2; ++i){
                swap(next[i], next[next.size()-1-i]);
            }
        }
        ans.push_back(ret);
        if(next.size() != 0){
            sub(ans, next, !left_to_right);
        }
    }
};