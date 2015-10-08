/*
题目：18 % 统计比给定整数小的数的个数 中等

题目大意：
给定一个数组。一些查询，问小于某个数的个数是多少？

解题思路：
其实可以用排序然后二分查找的方法
但是题目中有说可以用线段树。所以就用线段树解了

遇到的问题：
没有太大问题。
*/
class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> cnt(10001);
        for (auto a : A) {
            cnt[a]++;
        }
        auto root = build(cnt, 0, 10000);
        vector<int> ans(queries.size());
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = query(root, 0, queries[i]-1);
        }
        return ans;
    }
    
private:
    struct SegmentTreeNode {
        int start, end, cnt;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int s, int e, int c) {
            start = s;
            end = e;
            cnt = c;
        }
    };
    
    SegmentTreeNode *build(vector<int> &v, int left, int right) {
        if (left > right) return NULL;
        if (left == right) {
            auto ret = new SegmentTreeNode(left, right, v[left]);
            return ret;
        }
        auto ret = new SegmentTreeNode(left, right, 0);
        ret->left = build(v, left, (left+right)/2);
        ret->right = build(v, (left+right)/2+1, right);
        ret->cnt = ret->left->cnt + ret->right->cnt;
        return ret;
    }
    
    int query(SegmentTreeNode *root, int left, int right) {
        if (left > right) return 0;
        if (root->start >= left && root->end <= right) return root->cnt;
        if (root->start > right || root->end < left) return 0;
        return query(root->left, left, right) + query(root->right, left, right);
    }
};
