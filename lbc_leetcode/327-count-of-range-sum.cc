/*
题目大意：
给定一个数组，一个区间[low, upper]
问所有的数组的子数组的和在该区间的个数

解题思路：
最简单的肯定是直接计算出每个区间的和，然后判断一下。n*n的复杂度。
然后就死活想不出来别的解法了。
看到别人的思路之后感觉大开眼界啊，直接做了一个题，是判断每个数字后面有多少小于该数字的数。
然后形式化就是arr[i]-arr[j] (j > i && j < n)的个数
然后这个问题的形式化就是sum[j]-sum[i] <= upper && sum[j]-sum[i] >= low (j > i && j < n)
然后就又可以用mergeSort的变形来解了。

遇到的问题：
一开始把upper函数写成了lower了，所以一直错。

再次阅读：
思路已经是借鉴的最好的思路了。当然了这个题目，还有之前那个判断数字后面有多少小于该数字的数
的题目都是一样的解法，既可以用mergerSort也可以用SegmentTree
*/
class Solution {
private:
    int lower(vector<long long> &sum, int left, int right, long long val) {
        int ans = right+1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (sum[mid] < val) {
                left = mid+1;
            } else {
                ans = min(ans, mid);
                right = mid-1;
            }
        }
        return ans;
    }
    
    int upper(vector<long long> &sum, int left, int right, long long val) {
        int ans = right+1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (sum[mid] <= val) {
                left = mid+1;
            } else {
                ans = min(ans, mid);
                right = mid-1;
            }
        }
        return ans;
    }
    
    int mergeSort(vector<long long> &sum, int left, int right, int LOW, int UP) {
        if (left >= right) return 0;
        
        int L = left, R = right;
        
        int mid = (left + right) >> 1;
        int ans = 0;
        ans += mergeSort(sum, left, mid, LOW, UP);
        ans += mergeSort(sum, mid+1, right, LOW, UP);
        
        for (int i = left; i <= mid; ++i) {
            int low = lower(sum, mid+1, right, sum[i]+LOW);
            int up = upper(sum, mid+1, right, sum[i]+UP);
            ans += up - low;
        }
        
        vector<long long> tmp(sum.begin()+L, sum.begin()+R+1);
        int i = L, j = 0, k = mid+1-L;
        while (j + L <= mid && k+L <= right) {
            if (tmp[j] > tmp[k]) {
                sum[i++] = tmp[k++];
            } else {
                sum[i++] = tmp[j++];
            }
        }
        
        while (j + L <= mid) {
            sum[i++] = tmp[j++];
        }
        
        return ans;
    }
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        if (nums.size() < 1) return 0;
        
        vector<long long> sum(nums.size()+1, 0);
        for (int i = 1; i < sum.size(); ++i) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        
        int ans =  mergeSort(sum, 0, sum.size()-1, lower, upper);
        
        return ans;
    }
    
    int countRangeSum2(vector<int> &nums, int lower, int upper) {
        if (nums.size() < 1) return 0;
        
        vector<long long> sum(nums.size());
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] = nums[i] + sum[i-1];
        }
        
        int cnt = 0;
        for (int i = 0; i < sum.size(); ++i) {
            for (int j = i; j < sum.size(); ++j) {
                if (i == 0) {
                    if (sum[j] >= lower && sum[j] < upper) cnt++;
                } else {
                    if (sum[j]-sum[i-1] >= lower && sum[j]-sum[i-1] < upper) cnt++;
                }
            }
        }
        
        return cnt;
    }
};
/*
第二次做：
这道题应该算是挺难的了。
这次又没有想出来。
实现的时候也有点小问题，把指针当做左右边界了。
另外就是，如果整数都到了边界了，就没有办法计算mid了啊。加也不是，减也不是。
*/
class Solution {
    typedef long long LL;
    
    class SegmentTreeNode {
    public:
        LL start, end, cnt;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(LL s, LL e) {
            start = s;
            end = e;
            cnt = 0;
            left = right = NULL;
        }
    };
    
    SegmentTreeNode *root;
    
    void insert(SegmentTreeNode *node, LL val) {
        if (node->start != node->end) {
            LL mid = (node->start+node->end) >> 1;
            if (val > mid) {
                if (node->right == NULL) node->right = new SegmentTreeNode(mid+1, node->end);
                insert(node->right, val);
            } else {
                if (node->left == NULL) node->left = new SegmentTreeNode(node->start, mid);
                insert(node->left, val);
            }
        }
        node->cnt++;
        //cout << "insert " << val << " " << node->start << " " << node->end << " " << node->cnt << endl;
    }
    
    LL count(SegmentTreeNode *node, LL left, LL right) {
        //cout << "count " << left << " " << right << endl;
        if (node == NULL || node->start > right || node->end < left) return 0;
        if (node->start >= left && node->end <= right) return node->cnt;
        return count(node->left, left, right) + count(node->right, left, right);
    }
    
    void destroy(SegmentTreeNode *node) {
        if (node->left) destroy(node->left);
        if (node->right) destroy(node->right);
        delete node;
    }
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0) return 0;
        
        root = new SegmentTreeNode(LONG_LONG_MIN/2, LONG_LONG_MAX/2);
        
        vector<LL> sum(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sum[i+1] = sum[i] + nums[i];
        }
        
        int ans = 0;
        for (int i = sum.size()-1; i >= 0; --i) {
            ans += count(root, sum[i]+lower, sum[i]+upper);
            insert(root, sum[i]);
        }
        
        destroy(root);
        return ans;
    }
};