#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Given an integer array in the construct method, implement two methods query(start, end) and modify(index, value):
 *          For query(start, end), return the sum from index start to index end in the given array.
 *          For modify(index, value), modify the number in the given index to value
 * Solve: just do it.
 * Tips: the boundary can think more
 */
class SegTreeNode{
    public:
        int start, end;
        SegTreeNode *left, *right;
        long long sum;

        SegTreeNode(int start, int end, long long sum) {
            this->start = start;
            this->end = end;
            this->sum = sum;
            this->left = this->right = NULL;
        }
};

class Solution {
    public:
        // we need not vector A actually
        // because we store every index and element in the leaf
        vector<int> A;
        SegTreeNode *root;

        SegTreeNode *build(int start, int end) {
            if (start > end) return NULL;

            if (start == end) {
                return new SegTreeNode(start, end, A[start]);
            }

            SegTreeNode *root = new SegTreeNode(start, end, 0);
            int mid = (start + end) / 2;

            root->left = build(start, mid);
            root->right = build(mid+1, end);

            // we need not judge if the left/right child pointer
            // is null or not actually, because when the procedure
            // run to here, there are at least two children for
            // root. Because the leaf and NULL has been handled
            root->sum += root->left ? root->left->sum : 0;
            root->sum += root->right ? root->right->sum : 0;

            return root;
        }

        /**
         * @param A: An integer vector
         */
        Solution(vector<int> A) {
            this->A = A;
            this->root = build(0, A.size()-1);
        }

        /**
         * @param start, end: Indices
         * @return: The sum from start to end
         */
        long long query(int start, int end) {
            if (start < 0) start = 0;
            if (end > A.size()-1) end = A.size() -1 ;
            return subQuery(root, start, end);
        }
        long long subQuery(SegTreeNode *root, int start, int end) {
            if (start > end || root == NULL) return 0;

            if (root->start == start && root->end == end) return root->sum;

            int mid = (root->start + root->end) / 2;
            if (end <= mid) return subQuery(root->left, start, end);
            if (start > mid) return subQuery(root->right, start, end);

            return subQuery(root->left, start, mid) + subQuery(root->right, mid+1, end);
            // another way to query
            /*
            if (start > end || root == NULL) return 0;

            if (root->start >= start && root->end <= end) return root->sum;
            if (end < root->start || start > root->end) return 0;
            return subQuery(root->left, start, end) + subQuery(root->right, start, end);
            */
        }

        /**
         * @param index, value: modify A[index] to value.
         */
        void modify(int index, int value) {
            if (index < 0 || index > A.size()-1) return;

            A[index] = value;
            subModify(root, index, value);
        }

        void subModify(SegTreeNode *root, int index, int value) {
            if (root == NULL || index < root->start || index > root->end) return;

            if (root->start == root->end && root->start == index) {
                root->sum = value;
                return;
            }

            int mid = (root->start + root->end) / 2;

            if (index <= mid) subModify(root->left, index, value);
            if (index > mid) subModify(root->right, index, value);

            long long left = root->left ? root->left->sum : 0;
            long long right = root->right ? root->right->sum : 0;

            //root->sum = max(root->sum, left+right);
            // why max, it's a magic written. I don't why use max just then
            root->sum = left + right;
        }
};

int main()
{
    int arr[] = {1,2,33,4,8,8,1,2,7,8,5};
    vector<int> A(arr, arr+11);
    Solution s(A);
    cout << s.query(-1, -2) << endl;

    return 0;
}
