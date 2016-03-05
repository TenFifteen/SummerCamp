/*
题目大意：
与102类似，不过是从左往右一层，从右往左一层。

解题思路：
递归，注意左右顺序。

遇到的问题：
没问题。

再次阅读：
在DISCUSS中找到一个只用一个queue，并且不需要翻转数组的方法，感觉还是挺巧妙的：
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) {
        return vector<vector<int> > ();
    }
    vector<vector<int> > result;

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while ( !nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;
            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
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
/*
第二次做：
嗯，还是DISCUSS中这种思路还一些，可以省去了翻转数组的过程。而且只用一个队列就行了。
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
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        
        vector<TreeNode *> v;
        v.push_back(root);
        bool left_to_right = true;
        while (v.size()) {
            vector<TreeNode *> next;
            vector<int> cur;
            if (left_to_right) {
                for (int i = 0; i < v.size(); ++i) {
                    cur.push_back(v[i]->val);
                    if (v[i]->left) next.push_back(v[i]->left);
                    if (v[i]->right) next.push_back(v[i]->right);
                }
            } else {
                for (int i = v.size()-1; i >= 0; --i) {
                    cur.push_back(v[i]->val);
                    if (v[i]->right) next.push_back(v[i]->right);
                    if (v[i]->left) next.push_back(v[i]->left);
                }
                for (int i = 0; i < next.size()/2; ++i) {
                    swap(next[i], next[next.size()-1-i]);
                }
            }
            
            left_to_right = !left_to_right;
            v.swap(next);
            ans.push_back(cur);
        }
        
        return ans;
    }
};