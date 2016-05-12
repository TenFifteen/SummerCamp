/**
 * Problem: Given number n. Print number from 1 to n. But:
 *               when number is divided by 3, print "fizz".
 *               when number is divided by 5, print "buzz".
 *               when number is divided by both 3 and 5, print "fizz buzz".
 * Solve: just do it
 * Tips: lay judgement of 15 first
 */
class Solution {
    public:
        /**
         * param n: As description.
         * return: A list of strings.
         */
        vector<string> fizzBuzz(int n) {
            vector<string> results;
            for (int i = 1; i <= n; i++) {
                if (i % 15 == 0) {
                    results.push_back("fizz buzz");
                } else if (i % 5 == 0) {
                    results.push_back("buzz");
                } else if (i % 3 == 0) {
                    results.push_back("fizz");
                } else {
                    results.push_back(to_string(i));
                }
            }
            return results;
        }
};
