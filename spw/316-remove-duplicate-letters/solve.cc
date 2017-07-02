/**
 * Problem: Given a string which contains only lowercase letters, remove duplicate
 *          letters so that every letter appear once and only once. You must make sure
 *          your result is the smallest in lexicographical order among all possible results.
 * Solve: stack: compare neighbors every time, remove some elements and we meet new neighbors.
 * Tips: 1. use a has set;
 *       2. the sequence. (skip and minus count)
 *       3. pop unset has set.
 */
class Solution {
    public:
        string removeDuplicateLetters(string s) {
            char cnt[256] = {0};
            bool has[256] = {false};
            for (char c : s) ++cnt[c];

            stack<char> seq;
            for (char c : s) {
                if (has[c]) { --cnt[c]; continue; }

                while (!seq.empty() && cnt[seq.top()] > 1 && c < seq.top()) {
                    --cnt[seq.top()];
                    has[seq.top()] = false;
                    seq.pop();
                }

                seq.push(c);
                has[c] = true;
            }

            int pos = seq.size();
            string res(pos--, ' ');

            while (pos >= 0) {
                res[pos--] = seq.top();
                seq.pop();

            }

            return res;

        }

};
