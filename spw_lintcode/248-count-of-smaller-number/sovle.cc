#include <iostream>
#include <vector>

using namespace std;


/**
 * Problem: Give you an integer array (index from 0 to n-1, where n is the size of this
 *          array, value from 0 to 10000) and an query list. For each query, give you
 *          an integer, return the number of element in the array that are smaller than
 *          the given integer.
 * Solve: loop, sort, segment tree.
 * Tips: see comments below
 */
class Solution {
    public:
        /**
         * @param A: An integer array
         * @return: The number of element in the array that
         *          are smaller that the given integer
         */
        vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
            // write your code here
            int n = A.size();
            mysort(A, 0, n - 1);

            int m = queries.size();
            vector<int> ans(m, 0);
            for (int i = 0; i < m; ++i) {
                ans[i] = binarySearch(A, queries[i]);
            }

            return ans;
        }

    private:
        // time limit exceeded
        vector<int> loopSolve(vector<int> &A, vector<int> &queries) {
            int n = A.size();
            int m = queries.size();

            vector<int> ans(m, 0);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (A[j] < queries[i]) {
                        ans[i]++;
                    }
                }
            }

            return ans;
        }

        int binarySearch(vector<int> &A, int num) {
            int left = 0, right = A.size() - 1;
            // when the size = 0
            if (left > right) return 0;

            if (num <= A[left]) return 0;
            else if (num > A[right]) return A.size();

            while (left <= right) {
                int mid = left + (right- left) / 2;
                if (A[mid] > num) {
                    right = mid - 1;
                } else if (A[mid] < num) {
                    left = mid + 1;
                } else {
                    int i = mid-1;
                    while (i >= 0 && A[i] == A[mid]) {
                        --i;
                    }
                    return i + 1;
                }
            }

            return right;
        }

        void swap(vector<int> &A, int i, int j) {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
        void mysort(vector<int> &A, int left, int right) {
            if (left > right) return;

            int last = left;
            int mid = left + (right - left) / 2;
            swap(A, left, mid);
            for (int i = left+1; i <= right; ++i) {
                if (A[i] < A[left]) {
                    swap(A, i, ++last);
                }
            }

            swap(A, left, last);
            mysort(A, left, last-1);
            mysort(A, last+1, right);
        }

};

int main()
{
    Solution *s = new Solution();
    int nums[] = {1,2,3,4,5,6};
    int queries[] = {1,2,3,4};

    vector<int> n(nums, nums+6);
    vector<int> q(queries, queries+4);
    vector<int> ans = s->countOfSmallerNumber(n, q);
    for (int i = 0; i < ans.size(); ++i) {
         cout << ans[i] << " ";
    }
    cout << endl;
}
