/**
 *  Problem: Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.
 *           If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.
 *  Solve: each digit, then the factor must be >= 0 && <= 9
 *  Tips: digits as less as possible, then the 3*3 must be replace with 9
 */
class Solution {
    public:
        int smallestFactorization(int a) {
            if (a < 10) return a;

            stack<int> factors;
            bool res = getFactors(factors, a);

            if (!res) return 0;
            return getNum(factors);
        }

        bool getFactors(stack<int> &factors, int num) {
            for (int i = 9; i >= 2; --i) {
                while(num % i == 0) {
                    factors.push(i);
                    num /= i;

                    if (factors.size() > 31) return false;
                }
            }

            return num == 1;
        }

        long getNum(stack<int> &factors) {
            long res = 0;
            while (!factors.empty()){
                res = res * 10 + factors.top();
                factors.pop();
            }

            return res > INT_MAX ? 0 : res;
        }
};
