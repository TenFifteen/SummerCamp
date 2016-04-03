/**
 * Problem: The count-and-say sequence is the sequence of integers beginning as follows:
 *          1, 11, 21, 1211, 111221, ...
 * Solve: iterator as the given rule.
 * Tips: see comments below.
 */
class Solution {
    public:
        /**
         * @param n the nth
         * @return the nth sequence
         */
        string countAndSay(int n) {
            string it = "1";
            int i = 1;
            while (i < n) {
                string tmp;

                int cnt = 1;
                char last = it[0];
                for (int j = 0; j < it.size(); ++j) {
                    if (it[j] != last) {
                        tmp += to_string(cnt);
                        tmp += last;
                        last = it[j];
                        cnt = 1;
                    } else {
                        cnt++;
                    }
                }
                // the last
                tmp += to_string(cnt);
                tmp += last;

                ++i;
                it = tmp;
            }

            return it;
        }
};
