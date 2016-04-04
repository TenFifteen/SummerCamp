/**
 * Problem: Given n and k, return the k-th permutation sequence.
 * Solve: use (k-1) / fac(n-1) to determine the character in first position
 * Tips: see comments below
 */
class Solution {
    public:
        /**
         * @param n: n
         * @param k: the kth permutation
         * @return: return the k-th permutation
         */
        string getPermutation(int n, int k) {
            int fac[n+1];
            fac[0] = 1;
            vector<char> nums(n);
            for (int i = 1; i <= n; ++i) {
                fac[i] = i * fac[i-1];
                nums[i-1] = (char)(i + '0');
            }

            string ans;
            for (int i = n-1; i >= 0; --i) {
                // must be k-1 instead of k, because
                // index come from 0
                int index = (k-1) / fac[i];

                ans += nums[index];
                nums.erase(nums.begin()+index);
                k -= fac[i] * index;
            }

            return ans;
        }

};
