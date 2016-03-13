/**
 * Problem: What if the citations array
 *          is sorted in ascending order
 * Solve: binary search.
 * Tips: use particular case to handle the boundary.
 * 0 1 2 3 5
 * 0
 * 1
 */
class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int n = citations.size();
            int iter = n;

            while (iter--) {
                int count = n - iter - 1;
                if (citations[iter] <= count) {
                    return count;

                }

            }

            return n;

        }

};
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int iter = n;


        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            int val = citations[mid];
            int cnt = n - 1 - mid;

            if (val < cnt) {
                left = mid + 1;
            } else if (val > cnt) {
                right = mid - 1;
            } else {
                return cnt;
            }
        }

        return n - left;
    }
};
