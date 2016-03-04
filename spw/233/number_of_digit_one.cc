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
