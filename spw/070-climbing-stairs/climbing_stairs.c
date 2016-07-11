/**
 * Problem: You are climbing a stair case. It takes n steps to reach to the top.
 *          Each time you can either climb 1 or 2 steps.
 * Solve: Fibonacci
 * Tips: none
 */
int climbStairs(int n) {
	if (n <= 1) return 1;

	int prev1 = 1, prev2 = 1, ans = 1;
	int step = 2;
	while (step <= n) {
		ans = prev1 + prev2;
		prev1 = prev2;
		prev2 = ans;

		step++;
	}

	return ans;
}

class Solution {
public:
    int climbStairs(int n) {
        static vector<int> ans(2, 1);

        while (ans.size() <= n) {
            ans.push_back(ans[ans.size()-1] + ans[ans.size()-2]);
        }

        return ans[n];
    }
};
