/**
 * Problem: give an integer and find all the possible parentheses' sequences
 * Solve: find a method in the disscuss board!!
 *		  limiting condition: place the left parenthese first,
 *		  then we need a right one. Along with this way, we find
 *		  that we can use two conters. First sub left:n and add
 *		  the right at the same time. then sub right.
 * Tips: m and n must be greater than 0
 *
 */
void sub(vector<string> &ans, string now, int n, int m) {
    if (!m && !n) {
        ans.push_back(now);
    }

    if (n > 0) {
        sub(ans, now+'(', n-1, m+1);
    }

    if (m > 0) {
        sub(ans, now+')', n, m-1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    sub(ans, "", n, 0);
    return ans;
}

/**
 * At first, left have n zhibiao, and right have zero, when
 * add one left parenthese, we get one more right zhibiao
 */
class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            sub(ans, "", n, 0);

            return ans;
        }

        void sub(vector<string> &ans, string now, int left, int right) {
            if (left == 0 && right == 0) {
                ans.push_back(now);
                return;
            }

            if (left) sub(ans, now+'(', left-1, right+1);
            if (right) sub(ans, now+')', left, right-1);
        }
};
