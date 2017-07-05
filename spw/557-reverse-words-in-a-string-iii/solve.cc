/**
 * Problem: Given a string, you need to reverse the order of characters
 *          in each word within a sentence while still preserving
 *          whitespace and initial word order.
 *
 *          Example 1:
 *          Input: "Let's take LeetCode contest"
 *          Output: "s'teL ekat edoCteeL tsetnoc"
 * Solve: stack
 * Tips: pos++ < n
 */
class Solution {
    public:
        string reverseWords(string s) {
            reverse(s.begin(), s.end());

            stack<string> wordStack;
            int pos = 0, n = s.size(), prev = 0;
            while (pos++ < n) {
                if (s[pos] == ' ' || pos == n) {
                    wordStack.push(s.substr(prev, pos-prev));
                    prev = pos + 1;
                }
            }

            string res;
            while (!wordStack.empty()) {
                res += wordStack.top();
                wordStack.pop();

                if (!wordStack.empty()) {
                    res += " ";
                }
            }

            return res;
        }
};
