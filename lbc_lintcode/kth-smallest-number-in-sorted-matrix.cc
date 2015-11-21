/*
题目：16 % 排序矩阵中的从小到大第k个数 中等

题目大意：
给定一个矩阵，其中每行和每列都是排序的。问其中第k小的数是多少？

解题思路：
现将第一行放进一个最小堆里。然后这时候堆里的最小值就是整个矩阵的最小值；
然后依次删掉最小值，如果最小值在矩阵的下方还有值，就将该值放到堆中。
可以保证每次堆中的最小值就是除了前面删掉的元素的最小值。
所以做k-1次之后，堆中的最小值就是第k小的值。

遇到的问题：
没有想到该算法，还是参考的别人的思路。
https://lefttree.gitbooks.io/leetcode/content/dataStructure/heap/kthSmallestInMatrix.html
*/
class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    struct Node {
        int row, col, val;
        Node (int r, int c, int v) {
            row = r;
            col = c;
            val = v;
        }
        bool operator< (const Node &n) const {
            return this->val < n.val;
        }
    };
    
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        int n = matrix.size();
        int m = matrix[0].size();
        multiset<Node> ms;
        for (int i = 0; i < m; ++i) {
            ms.insert(Node(0, i, matrix[0][i]));
        }
        for (int i = 0; i < k-1; ++i) {
            auto cur = *ms.begin();
            ms.erase(ms.find(cur));
            if (cur.row+1 < n) {
                ms.insert(Node(cur.row+1, cur.col, matrix[cur.row+1][cur.col]));
            }
        }
        return ms.begin()->val;
    }
};
