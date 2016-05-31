/**
 * Problem: Given a non negative integer number num. For every numbers i
 *          in the range 0 ≤ i ≤ num calculate the number of 1's in their bi
 *          nary representation and return them as an array.
 * Solve: static variable + dp
 * Tips: ans[i] = ans[i>>1] + (i&1)
 */
class Solution {
    public:
        vector<int> countBits(int num) {
            static vector<int> ans(1, 0);

            if (ans.size() > num) {
                vector<int> tmp(ans.begin(), ans.begin()+1+num);
                return tmp;
            }

            for (int i = ans.size(); i <= num; ++i) {
                ans.push_back(ans[i>>1] + (i & 1));
            }
            return ans;
        }
};
