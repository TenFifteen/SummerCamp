/**
 * Problem: The gray code is a binary numeral system
 *          where two successive values differ in only one bit.
 * Solve: recursive
 * Tips: no
 */
class Solution {
    public:
        void sub(vector<int> &pre, int bitCount) {
            if (bitCount == 0) {
                pre.push_back(0);
                return;
            }

            sub(pre, bitCount-1);
            int n = pre.size();
            int mask = 1 << (bitCount - 1);
            for (int i = n-1; i >= 0; --i) {
                pre.push_back(pre[i] | mask);
            }
        }
        /**
         ** @param n a number
         ** @return Gray code
         **/
        vector<int> grayCode(int n) {
            vector<int> ans;

            if (n < 0) return ans;

            sub(ans, n);
            return ans;
        }
};
