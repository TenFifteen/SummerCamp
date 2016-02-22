/*
题目大意：
给定一个n，写出由1-n组成的所有的平衡二叉树的结果。

解题思路：
动态规划。选定一个顶点，分别求左侧和右侧。

遇到的问题：
竟然在n==0的时候返回一个vector里，带一个NULL。
初次之外无其他问题。

再次阅读：
感觉这种解法比较正常了。
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
    vector<TreeNode*> generateTrees(int n) {
        return sub(1, n);
    }
    
    vector<TreeNode *> sub(int left, int right){
        vector<TreeNode *> ret;
        if(left > right){
            ret.push_back(NULL);
            return ret;
        }
        if(left == right){
            ret.push_back(new TreeNode(left));
            return ret;
        }
        for(int i = left; i <= right; ++i){
            vector<TreeNode *> ll = sub(left, i-1);
            vector<TreeNode *> rr = sub(i+1, right);
            for(int j = 0; j < ll.size(); ++j){
                TreeNode *head = new TreeNode(i);
                if(j == ll.size()-1){
                    head->left = ll[j];
                }else{
                    head->left = copy(ll[j]);
                }
                for(int k = 0; k < rr.size(); ++k){
                    if(k == rr.size()-1){
                        head->right = rr[k];
                        ret.push_back(head);
                    }else{
                        TreeNode *tmp = copy(head);
                        tmp->right = copy(rr[k]);
                        ret.push_back(tmp);
                    }
                }
            }
        }
        return ret;
    }
    
    TreeNode *copy(TreeNode *head){
        if(head == NULL)return NULL;
        TreeNode *ret = new TreeNode(head->val);
        ret->left = copy(head->left);
        ret->right = copy(head->right);
    }
};