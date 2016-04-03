/**
 * Problem: Find the Nth number in Fibonacci sequence.
 * Solve: static array
 * Tips: notice the index.
 */
class Solution{
    public:
        /**
         * @param n: an integer
         * @return an integer f(n)
         */
        int fibonacci(int n) {
            // write your code here
            static vector<int> ans;
            if (ans.empty()) {
                ans.push_back(0);
                ans.push_back(1);
            }

            // if i reach the count then return,
            // count one by to n otherwise
            int i = ans.size();
            while (i < n) {
                ans.push_back(ans[i-1] + ans[i-2]);
                ++i;
            }

            return ans[n-1];
        }
};
