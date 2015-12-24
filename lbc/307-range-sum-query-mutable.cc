/*
题目大意：
给定给一个数组，数组的元素可以更新。
然后动态的求子数组的和。

解题思路：
线段树。
其实可以用树状数组的，但是我感觉树状数组不是很熟，而且应用范围也没有线段树广。

遇到的问题：
没有问题。
每次线段树都是一次写对。
我发现，我其实比较擅长写这种迭代类型的树的。
*/
class NumArray {
    struct Node {
        long long sum;
        int a, b;
        Node *left, *right;
        
        Node() {
            left = right = NULL;
        }
    };
    
    Node *create(vector<int> &nums, int left, int right) {
        if (left > right) return NULL;
        if (left == right) {
            Node *ans = new Node();
            ans->sum = nums[left];
            ans->a = ans->b = left;
            return ans;
        }
        
        int mid = left + (right-left)/2;
        Node *left_child = create(nums, left, mid);
        Node *right_child = create(nums, mid+1, right);
        
        Node *ans = new Node();
        ans->sum = left_child->sum + right_child->sum;
        ans->left = left_child;
        ans->right = right_child;
        ans->a = left;
        ans->b = right;
        
        return ans;
    }
    
    Node *root;
    
    void up(Node *root, int index, int val) {
        if (root == NULL) return;
        if (root->a == root->b) {
            root->sum = val;
            return;
        }
        
        int mid = root->a + (root->b - root->a)/2;
        if (index <= mid) {
            up(root->left, index, val);
        } else {
            up(root->right, index, val);
        }
        
        root->sum = root->left->sum + root->right->sum;
    }
    
    int getSum(Node *root, int left, int right) {
        if (root == NULL) return 0;
        if (left <= root->a && right >= root->b) {
            return root->sum;
        }
        if (left > root->b || right < root->a) {
            return 0;
        }
        
        return getSum(root->left, left, right) + getSum(root->right, left, right);
    }
    
public:
    NumArray(vector<int> &nums) {
        if (nums.size() != 0) root = create(nums, 0, nums.size()-1);
        else root = NULL;
    }

    void update(int i, int val) {
        up(root, i, val);
    }

    int sumRange(int i, int j) {
        getSum(root, i, j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);