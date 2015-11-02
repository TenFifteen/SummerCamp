/*
题目：17 % 统计前面比自己小的数的个数 困难

题目大意：
给定一个数组，计算每个数字前面有多少个比它小的数字。数组的值是从0-10000

解题思路：
线段树。每次添加一个数字进入线段树中，然后查询一下在它前面的数字有多少。

遇到的问题：
一开始没想到线段树怎么弄。后来看了别人的思路，才知道动态的维护信息，感觉也是挺好的。
参考：
http://www.cnblogs.com/EpisodeXI/p/4585770.html
不过别人也说可以直接用树状数组，好像是挺有道理的哈。毕竟每次查询都是0-index。可以直接用
树状数组了。
http://www.cnblogs.com/easonliu/p/4575645.html
*/
class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    struct SegmentTreeNode {
        int start, end;
        SegmentTreeNode *left, *right;
        int cnt;
        SegmentTreeNode(int l, int r) {
            start = l;
            end = r;
            cnt = 0;
            left = NULL;
            right = NULL;
        }
    };
    
    SegmentTreeNode *build(int left, int right) {
        if (left > right) return NULL;
        auto ret = new SegmentTreeNode(left, right);
        if (left == right) return ret;
        int mid = left + (right-left+1)/2;
        ret->left = build(left, mid-1);
        ret->right = build(mid, right);
        return ret;
    }
    
    int query(int left, int right, SegmentTreeNode *root) {
        if (left <= root->start && right >= root->end) {
            return root->cnt;
        }
        if (left > root->end || right < root->start) {
            return 0;
        }
        return query(left, right, root->left) + query(left, right, root->right);
    }
    
    void modify(int index, SegmentTreeNode *root) {
        if (root == NULL || root->start > index || root->end < index) {
            return;
        }
        root->cnt++;
        modify(index, root->left);
        modify(index, root->right);
    }
    
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        auto root = build(0, 10000);
        vector<int> ans(A.size());
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = query(0, A[i]-1, root);
            modify(A[i], root);
        }
        return ans;
    }
};
