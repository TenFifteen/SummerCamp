/*
题目：25 % 第k个排列 中等

题目大意：
给定一个n，一个k。问从1-n的排列的第k个排列是什么？

解题思路：
直接用数学计算的方法做，见代码

遇到的问题：
没有问题。
不过这种代码写起来好难受啊。
*/
class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        string ans;
        vector<int> buf(n);
        buf[0] = 1;
        for (int i = 1;i < n; ++i) {
            buf[i] = (i+1) * buf[i-1];
        }
        vector<bool> visit(n, false);
        for (int i = 0; i < n; ++i) {
            if (k == 1 || k <= buf[n-2-i]) {
                int cur;
                for (int i = 0; i < n; ++i) {
                    if (visit[i] == false) {
                        cur = i+1;
                        visit[i] = true;
                        break;
                    }
                }
                ans += to_string(cur);
            } else {
                int index = k / buf[n-2-i];
                k %= buf[n-2-i];
                if (k == 0) {
                    index--;
                    k = buf[n-2-i];
                }
                int cur = 0;
                while (index >= 0) {
                    if (!visit[cur]) {
                        index--;
                    }
                    cur++;
                }
                visit[cur-1] = true;
                ans += to_string(cur);
            }
        }
        return ans;
    }
};
