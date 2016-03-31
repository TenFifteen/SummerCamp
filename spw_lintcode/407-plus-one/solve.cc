/**
 * Problem: Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 * Solve: just do it
 * Tips: no
 */
class Solution {
    public:
        /**
         ** @param digits a number represented as an array of digits
         ** @return the result
         **/
        vector<int> plusOne(vector<int>& digits) {
            int n = digits.size();

            int aside = 1;
            for (int i = n-1; i >= 0 && aside; --i) {
                int now = digits[i] + aside;
                digits[i] = now % 10;
                aside = now >= 10 ? 1 : 0;

            }

            if (aside == 0) return digits;

            vector<int> ans(n+1, 0);
            ans[0] = 1;
            for (int i = 0; i < n; ++i) ans[i+1] = digits[i];
            return ans;
        }
};
