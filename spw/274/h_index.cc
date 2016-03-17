/**
 * Problem: Given an array of citations (each citation is a
 *          non-negative integer) of a researcher, write a
 *          function to compute the researcher's h-index.
 * Solve: sort and find.
 * Tips: handle <=
 */
class Solution {
    private:
        static bool cmp(const int &a, const int &b) {
            return a > b;

        }
    public:
        int hIndex(vector<int>& citations) {
            sort(citations.begin(), citations.end(), cmp);

            int n = citations.size();
            for (int i = 0; i < n; ++i) {
                if (citations[i] <= i) {
                    return i;
                }
            }

            return n;
        }

};
