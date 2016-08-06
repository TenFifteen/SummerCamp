/*
 * https://discuss.leetcode.com/topic/45341/an-simple-explanation-of-the-math-part-and-a-o-n-solution
 * very good ans and explanation.
 */
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int ans = 1;
        while (n > 4) {
            ans *= 3;
            n -= 3;
        }
        ans *= n;
        return ans;
    }
};
