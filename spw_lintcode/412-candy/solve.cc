/**
 * Problem: There are N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 * ***Each child must have at least one candy.
 * ***Children with a higher rating get more candies than their neighbors.
 * Solve: use a vector.
 * Tips: see comments below.
 */
class Solution {
    public:
        /**
         *  * @param ratings Children's ratings
         *  * @return the minimum candies you must give
         *  */
        int candy(vector<int>& ratings) {
            int n = ratings.size();

            vector<int> dp(n, 1);
            for (int i = 1; i < n; ++i) {
                if (ratings[i] > ratings[i-1]) {
                    dp[i] = dp[i-1] + 1;

                }

            }

            int sum = 0;
            for (int i = n-1; i > 0; --i) {
                if (ratings[i] < ratings[i-1]) {
                    dp[i-1] = max(dp[i-1], dp[i]+1);
                }
                sum += dp[i];
            }
            sum += dp[0];

            return sum;

        }

};
