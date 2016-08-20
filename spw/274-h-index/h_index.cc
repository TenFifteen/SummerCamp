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

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n;
        while (left < right) {
            int h = (left + right) / 2;

            int more = 0, eq = 0;
            for (int i = 0; i < n; ++i) {
                if (citations[i] > h) ++more;
                else if (citations[i] == h) ++eq;
            }
            if (more <= h && h <= more+eq) return h;
            else if (more+eq < h) right = h - 1;
            else left = h + 1;
        }

        return left;
    }
};

// third solution: (n+1) size bucket.
