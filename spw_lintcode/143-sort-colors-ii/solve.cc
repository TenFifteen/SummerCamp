/**
 * Problem: Given an array of n objects with k different colors (numbered from 1 to k),
 *          sort them so that objects of the same color are adjacent,
 *          with the colors in the order 1, 2, ... k.
 * Solve: count sort use this vector
 * Tips: see comments below.
 */
lass Solution{
    public:
        /**
         * @param colors: A list of integer
         * @param k: An integer
         * @return: nothing
         */
        void sortColors2(vector<int> &colors, int k) {
            int n = colors.size();

            for (int i = 0; i < n; ++i) {
                while (colors[i] > 0) {
                    int index = colors[i] - 1;
                    if (colors[index] > 0) {
                        colors[i] = colors[index];
                        colors[index] = -1;
                    } else {
                        colors[index]--;
                        // marked as empty
                        colors[i] = 0;
                    }
                }
            }

            int index = n - 1;
            for (int i = k-1; i >= 0; --i) {
                int cnt = -colors[i];
                while (cnt--) {
                    colors[index--] = i + 1;
                }
            }
        }
};
