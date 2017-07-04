/**
 * Problem: Given a list of positive integers, the adjacent integers will
 *          perform the float division. For example, [2,3,4] -> 2 / 3 / 4.
 *
 *          However, you can add any number of parenthesis at any position
 *          to change the priority of operations. You should find out how
 *          to add parenthesis to get the maximum result, and return the
 *          corresponding expression in string format. Your expression should
 *          NOT contain redundant parenthesis.
 * Solve: a/b/c/d/e/f; a/b are all the same, the last can be reverse to mutiply
 * Tips: It it such a solution!
 */
class Solution {
    public:
        string optimalDivision(vector<int>& nums) {
            int n = nums.size();
            string res = "";

            if (n == 0) return res;

            res = to_string(nums[0]);
            if (n == 1) return res;
            if (n == 2) return res + "/" + to_string(nums[1]);

            res += "/(";
            for (int i = 1; i < n-1; ++i) {
                res += to_string(nums[i]) + "/";
            }
            res += to_string(nums[n-1]) + ")";

            return res;
        }
};
