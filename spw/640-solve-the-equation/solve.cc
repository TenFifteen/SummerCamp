/**
 * Problem: Solve a given equation and return the value of x in the form
 *          of string "x=#value". The equation contains only '+', '-'
 *          operation, the variable x and its coefficient.
 *
 *          If there is no solution for the equation, return "No solution".
 *
 *          If there are infinite solutions for the equation, return
 *          "Infinite solutions".
 *
 *          If there is exactly one solution for the equation,
 *          we ensure that the value of x is an integer.
 * Solve: 1. use sign and equal two flag variable
 *        2. use left and right two holder
 * Tips: 1. sign^equal instead of sign&&equal
 *       2. 0x and x(special cases
 *
 */
class Solution {
    public:
        string solveEquation(string equation) {
            int n = equation.size();
            int left = 0, right = 0;

            int pos = 0;
            bool sign = true, equal = true;
            while (pos != n) {
                if (equation[pos] >= '0' && equation[pos] <= '9' || equation[pos] == 'x') {
                    int digit = 0;
                    if (equation[pos] == 'x') digit = 1;
                    while (equation[pos] >= '0' && equation[pos] <= '9') {
                        digit = digit * 10 + (equation[pos++] - '0');
                    }

                    if (pos < n && equation[pos] == 'x') {
                        left += sign == equal ? digit : -digit;
                        ++pos;
                    } else {
                        right += sign == equal ? -digit : digit;
                    }

                    sign = true;
                } else if (equation[pos] == '=') {
                    equal = !equal;
                    ++pos;
                } else {
                    if (equation[pos] == '-')
                        sign = false;
                    ++pos;
                }
            }

            //cout << left << " " << right << endl;
            string res;
            if (left == 0 && right == 0) {
                res = "Infinite solutions";
            } else if (left == 0 && right != 0) {
                res = "No solution";
            } else {
                res = "x=" + to_string(right/left);
            }

            return res;
        }
};
