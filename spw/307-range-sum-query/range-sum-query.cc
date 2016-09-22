/**
 * Problem: Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 *          The update(i, val) function modifies nums by updating the element at index i to val.
 * Solve: segment tree.
 * Tips: see comments below.
 */
class SegNode {
    public:
        SegNode *left, *right;
        int start, end;
        int sum;

        SegNode(int s, int e) {
            this->sum = 0;
            this->start = s;
            this->end = e;
            this->left = this->right = NULL;
        }
};

class NumArray {
    SegNode *root;

    SegNode *buildTree(vector<int> &nums, int s, int e) {
        if (s > e) return NULL;

        SegNode *now = new SegNode(s, e);
        if (s == e) {
            now->sum = nums[s];
            return now;
        }

        // use mid(s and e) to route
        int mid = (s + e) / 2;
        now->left = buildTree(nums, s, mid);
        now->right = buildTree(nums, mid+1, e);
        now->sum = (now->left ? now->left->sum : 0) + (now->right ? now->right->sum : 0);

        return now;
    }

    // reduce range of root each time until [left, right] in [root->start, root->end]
    int getSum(SegNode *root, int left, int right) {
        if (root == NULL || left > root->end || right < root->start) return 0;

        if (left <= root->start && root->end <= right) return root->sum;
        return getSum(root->left, left, right) + getSum(root->right, left, right);
    }

    void setNum(SegNode *root, int pos, int val) {
        if (root == NULL) return;

        if (root->start == root->end && root->end == pos) {
            root->sum = val;
            return;
        }

        // use mid(root->start, root->end) to route
        int mid = (root->start + root->end) / 2;
        if (pos <= mid) setNum(root->left, pos, val);
        else setNum(root->right, pos, val);

        // remember to update recursively
        root->sum = (root->left ? root->left->sum : 0) + (root->right ? root->right->sum : 0);
    }
    public:
    NumArray(vector<int> &nums) {
        root = buildTree(nums, 0, nums.size()-1);
    }

    void update(int i, int val) {
        setNum(root, i, val);
    }

    int sumRange(int i, int j) {
        return getSum(root, i, j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
//
class SegNode {
    public:
        SegNode *left, *right;
        int start, end;
        int sum;
        SegNode(int s, int e, int n) {
            left = right = NULL;
            start = s, end = e;
            sum = n;
        }
};
class NumArray {
    private:
        SegNode *root;
    public:
        NumArray(vector<int> &nums) {
            root = buildTree(nums, 0, nums.size()-1);
        }

        SegNode* buildTree(vector<int> &nums, int left, int right) {
            if (left > right) return NULL;

            SegNode *root = new SegNode(left, right, 0);
            if (left == right) {
                root->sum = nums[left];
                return root;
            }

            int mid = (left + right) / 2;
            root->left = buildTree(nums, left, mid);
            root->right = buildTree(nums, mid+1, right);
            root->sum += root->left ? root->left->sum : 0;
            root->sum += root->right ? root->right->sum : 0;
            return root;
        }

        void update(int i, int val) {
            updateTree(root, i, val);
        }
        void updateTree(SegNode *root, int i, int val) {
            if (root == NULL || i < root->start || i > root->end) return;

            if (root->start == root->end) {
                if (root->start == i)
                    root->sum = val;
                return;
            }

            int mid = (root->start + root->end) / 2;
            if (i <= mid) updateTree(root->left, i, val);
            else updateTree(root->right, i, val);

            root->sum = 0;
            root->sum += root->left ? root->left->sum : 0;
            root->sum += root->right ? root->right->sum : 0;
        }

        int sumRange(int i, int j) {
            return sumTree(root, i, j);
        }
        int sumTree(SegNode *root, int left, int right) {
            if (root == NULL) return 0;

            if (root->start >= left && root->end <= right) return root->sum;

            if (left > root->end || right < root->start) return 0;

            return sumTree(root->left, left, right) + sumTree(root->right, left, right);
        }
};

