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

再次阅读：
感觉虽然线段树虽然没有什么问题，但是毕竟是有点大材小用了，而且对于这里这个情形来讲，
还是有些浪费空间的。
下面这套代码就是树状数组（BIT）的经典实现：
class NumArray {
public:
    NumArray(vector<int> &nums) {
        sz = nums.size();
        num = vector<int>(sz+1, 0);
        sum = vector<int>(sz+1, 0);
        for(int i=0; i<sz; i++) {
            update(i, nums[i]);
        }

    }

    void update(int idx, int val) {
        int oldv = num[idx+1];
        for(int i = idx+1; i<=sz; i+= (i&-i)) {
            sum[i] = sum[i] - oldv + val;
        }
        num[idx+1] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j+1) - getSum(i);
    }

    int getSum(int idx) {
        int ret = 0;
        for(int i=idx; i>0; i-=(i&-i)) {
            ret += sum[i];
        }
        return ret;
    }
private :
    int sz;
    vector<int> num;
    vector<int> sum;
};

DISCUSS中还有一种思路是用桶排序的思想，将输入数据划分为根号n个桶，然后计算每个桶的总和。
那么更新的话，就是一个O(1)复杂度的操作。然后算总和的时候，最多有两个桶需要单独计算，其他的桶都
可以直接取到总和。所以复杂度是根号n。
class NumArray {
public:

    struct Bucket
    {
        int sum;
        vector<int> val;
    };

    int bucketNum;
    int bucketSize;
    vector<Bucket> Bs;

    NumArray(vector<int> &nums) {
        int size = nums.size();
        int bucketNum = (int)sqrt(2*size);
        bucketSize = bucketNum/2;
        while(bucketSize * bucketNum<size) ++bucketSize;

        Bs.resize(bucketNum);
        for(int i=0, k=0; i<bucketNum; ++i)
        {
            int temp = 0;
            Bs[i].val.resize(bucketSize);
            for(int j=0; j<bucketSize && k<size; ++j, ++k)
            {
                temp += nums[k];
                Bs[i].val[j] = nums[k];
            }
            Bs[i].sum = temp;
        }
    }

    void update(int i, int val) {
        int x = i / bucketSize;
        int y = i % bucketSize;
        Bs[x].sum += (val - Bs[x].val[y]);
        Bs[x].val[y] = val;
    }

    int sumRange(int i, int j) {
        int x1 = i / bucketSize;
        int y1 = i % bucketSize;
        int x2 = j / bucketSize;
        int y2 = j % bucketSize;
        int sum = 0;

        if(x1==x2)
        {
            for(int a=y1; a<=y2; ++a)
            {
                sum += Bs[x1].val[a];
            }
            return sum;
        }

        for(int a=y1; a<bucketSize; ++a)
        {
            sum += Bs[x1].val[a];
        }
        for(int a=x1+1; a<x2; ++a)
        {
            sum += Bs[a].sum;
        }
        for(int b=0; b<=y2; ++b)
        {
            sum += Bs[x2].val[b];
        }
        return sum;
    }
};
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