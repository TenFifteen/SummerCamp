/**
 * problem: Given a set of n nuts of different sizes and n bolts of different sizes.
 *          There is a one-one mapping between nuts and bolts. Comparison of a nut to another
 *          nut or a bolt to another bolt is not allowed. It means nut can only be compared
 *          with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
 * Solve: partition
 * Tips: no
 */
class Solution {
    public:
        /**
         *      * @param nuts: a vector of integers
         *           * @param bolts: a vector of integers
         *                * @param compare: a instance of Comparator
         *                     * @return: nothing
         *                          */
        void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
            // write your code here
            //         if (nuts.size() == 0) return;
            //                 sub(nuts, bolts, 0, nuts.size()-1, compare);
            //
        }

        void sub(vector<string> &nuts, vector<string> &bolts, int left, int right, Comparator &compare) {
            if (left >= right) return;
            int l = left, r = right;
            while (l < r) {
                while (l < r && compare.cmp(nuts[left], bolts[l]) > 0) l++;
                while (l < r && compare.cmp(nuts[left], bolts[r]) < 0) r--;
                swap(bolts[l], bolts[r]);

            }

            int mid = l;
            l = left, r = right;
            while (l < r) {
                while (l < r && compare.cmp(nuts[l], bolts[mid]) < 0) l++;
                while (l < r && compare.cmp(nuts[r], bolts[mid]) > 0) r--;
                swap(nuts[l], nuts[r]);

            }

            sub(nuts, bolts, left, mid-1, compare);
            sub(nuts, bolts, mid+1, right, compare);

        }

};
