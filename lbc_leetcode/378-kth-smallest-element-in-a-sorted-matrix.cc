/*
 * ok
 */
class Solution {
private:
struct Node {
    int val;
    int x, y;
    Node(int x, int y, int v) : x(x), y(y), val(v) {}

    bool operator<(const Node &n) const {
        if (val < n.val) return true;
        else if (val > n.val) return false;
        return y < n.y;
    }
};

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<Node> ms;
        for (int i = 0; i < matrix[0].size(); ++i) {
            ms.insert(Node(0, i, matrix[0][i]));
        }

        for (int i = 1; i < k; ++i) {
            Node now = *ms.begin();
            cout << "now " << now.val << endl;
            ms.erase(now);
            if (now.x+1 < matrix.size()) {
                ms.insert(Node(now.x+1, now.y, matrix[now.x+1][now.y]));
            }
        }
        return ms.begin()->val;
    }
};
