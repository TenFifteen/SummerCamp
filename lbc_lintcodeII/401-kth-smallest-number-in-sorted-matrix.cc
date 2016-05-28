/*
题目大意：
给定一个矩阵，横着竖着都是排序的。问第k小的数是哪个？

解题思路：
见代码。

遇到的问题：
没有太大问题。

*/
class Solution {
    struct Node {
        int x, y, val;
        bool operator< (const Node &n) const {
            if (val < n.val) return true; // duplicate
            if (val > n.val) return false;
            return y < n.y;
        }
    };
    
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        if (matrix.size() == 0 || matrix[0].size() == 0) return -1;
        if (k < 1 || k > matrix.size() * matrix[0].size()) return -1;
        
        set<Node> s;
        for (int i = 0; i < matrix[0].size(); ++i) {
            Node node;
            node.x = 0;
            node.y = i;
            node.val = matrix[0][i];
            s.insert(node);
        }
        
        for (int i = 1; i < k; ++i) {
            Node now = *s.begin();
            s.erase(now);
            //cout << now.x << " " << now.y << now.val << endl;
            
            if (now.x + 1 < matrix.size()) {
                now.x++;
                now.val = matrix[now.x][now.y];
                s.insert(now);
            }
        }
        
        return s.begin()->val;
    }
};
