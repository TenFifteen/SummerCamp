/**
 * Problem: Given an array with positive and negative
 *          integers. Re-range it to interleaving with
 *          positive and negative integers.
 * Solve: use a virtual index
 * Tips: should know the count of positive and negative number first.
 */
class Solution {
    public:
        /**
         * @param A: An integer array.
         * @return: void
         */
        void rerange(vector<int> &A) {
            int n = A.size();
            if (n < 2) return;

            int ng = 0, po = 0;
            for (int i = 0; i < n; ++i)
                A[i] > 0 ? po++ : ng++;

#define num(i) A[(2 * i + 1) % (n | 1)]

            int l = 0, r = n -1;
            while (l <= r) {
                if (po >= ng) {
                    if (num(l) < 0) ++l;
                    else swap(num(l), num(r--));
                } else {
                    if (num(l) > 0) ++l;
                    else swap(num(l), num(r--));
                }
            }
        }
};
