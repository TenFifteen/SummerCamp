/**
 * Problem: Given a roman numeral, convert it to an integer.
 *          The answer is guaranteed to be within the range from 1 to 3999.
 * Solve: make a table map roman to decimal
 * Tips: because now > prev only occur in case like 'IV', there are no more
 *       than one character small before the bigger.This make it easy to solve.
 */
class Solution {
    public:
        /**
         * @param s Roman representation
         * @return an integer
         */
        int romanToInt(string& s) {
            static unordered_map<char, int> table;
            if (table.empty()) {
                table['I'] = 1;
                table['V'] = 5;
                table['X'] = 10;
                table['L'] = 50;
                table['C'] = 100;
                table['D'] = 500;
                table['M'] = 1000;
            }

            char prev = 'M';
            int ans = 0;
            for (int i = 0; i < s.size(); ++i) {
                ans += table[s[i]];
                if (table[s[i]] > table[prev]) {
                    ans -= 2*table[prev];
                }
                prev = s[i];
            }

            return ans;
        }
};
