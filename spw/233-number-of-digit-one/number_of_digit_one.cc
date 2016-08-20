#include <iostream>

using namespace std;

/**
 * Problem: Given an integer n, count the total number of
 *          digit 1 appearing in all non-negative integers
 *          less than or equal to n.
 * Solve: Count the 1 in every bit.
 * Tips: There are three cases, when the bit = 0, bit = 1, bit >1
 */
class Solution {
    public:
        int countDigitOne(int n) {
            if (n <= 0) return 0;
            int left = n / 10, right = 0;

            int count = 0;
            int p = 1;

            while (n) {
                int bit = n % 10;
                if (bit == 0) {
                    count +=  left  * p;

                } else if (bit == 1) {
                    count +=  (left  * p + right + 1);

                } else {
                    count += (left + 1) * p;

                }

                right = bit * p + right;
                left = left / 10;

                p = p * 10;
                n /= 10;

            }

            return count;

        }

};

int main()
{
    int num;
    while (cin >> num)
        cout << countDigitOne(num) << endl;

    return 0;
}

class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1) return 0;
        int cnt = 0;

        int split = 1;
        while (n >= split) {
            int right = n % split, left = n / split;
            int now = left % 10;
            left /= 10;

            if (now == 0) {
                cnt += left * split;
            } else if (now == 1) {
                cnt += left * split + right + 1;
            } else {
                cnt += (left + 1) * split;
            }

            // special case: n*10 > INT_MAX
            if (left == 0) break;
            split *= 10;
        }

        return cnt;
    }
};
