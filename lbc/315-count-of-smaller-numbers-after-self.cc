/*
题目大意：
给定一个数组，问每一个数字的后面比该数字小的数字的数量是多少？

解题思路：
用了一个线段树。

遇到的问题：
感觉线段树好像的确是用途挺广的。而且写下来感觉还是比较不错的。
不过题目中有提示说可以用BIT还有mergersort来解。不知道怎么写。。

再次阅读：
找了一下DISCUSS中的mergesort的解法，终于找到了一个。本来知道了这个思路之后，我也是想着这么实现
来着，只是没有想清楚下标应该怎么变化才行。下面这段代码值得好好的看看，尤其是关于indices数组的使用。
class Solution {
protected:
    void merge_countSmaller(vector<int>& indices, int first, int last, 
                            vector<int>& results, vector<int>& nums) {
        int count = last - first;
        if (count > 1) {
            int step = count / 2;
            int mid = first + step;
            merge_countSmaller(indices, first, mid, results, nums);
            merge_countSmaller(indices, mid, last, results, nums);
            vector<int> tmp;
            tmp.reserve(count);
            int idx1 = first;
            int idx2 = mid;
            int semicount = 0;
            while ((idx1 < mid) || (idx2 < last)) {
                if ((idx2 == last) || ((idx1 < mid) &&
                       (nums[indices[idx1]] <= nums[indices[idx2]]))) {
                    tmp.push_back(indices[idx1]);
                    results[indices[idx1]] += semicount;
                    ++idx1;
                } else {
                    tmp.push_back(indices[idx2]);
                    ++semicount;
                    ++idx2;
                }
            }
            move(tmp.begin(), tmp.end(), indices.begin()+first);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n, 0);
        vector<int> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);
        merge_countSmaller(indices, 0, n, results, nums);
        return results;
    }
};
*/
class Solution {
private:
    struct SegmentTreeNode {
        int L, R;
        int count;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int l, int r):L(l), R(r), count(0), left(nullptr), right(nullptr){}
    };
    
    void insert(SegmentTreeNode *root, int val) {
        root->count++;
        if (root->L == val && root->R == val) {
            return;
        }
        
        int mid = ((long long)root->L + root->R) >> 1;
        if (val <= mid) {
            if (root->left == nullptr) {
                root->left = new SegmentTreeNode(root->L, mid);
            }
            insert(root->left, val);
        } else {
            if (root->right == nullptr) {
                root->right = new SegmentTreeNode(mid+1, root->R);
            }
            insert(root->right, val);
        }
    }
    
    int getSmaller(SegmentTreeNode *root, int val) {
        if (root == nullptr) return 0;
        if (val > root->R) return root->count;
        if (val <= root->L) return 0;
        
        int mid = ((long long)root->L + root->R) >> 1;
        return getSmaller(root->left, val) + getSmaller(root->right, val);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        if (nums.size() < 2) return ans;
        
        SegmentTreeNode *root = new SegmentTreeNode(INT_MIN, INT_MAX);
        insert(root, nums[nums.size()-1]);
        for (int i = nums.size()-2; i >= 0; --i) {
            ans[i] = getSmaller(root, nums[i]);
            insert(root, nums[i]);
        }
        
        return ans;
    }
};