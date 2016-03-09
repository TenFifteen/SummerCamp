/*
 * Problem: write a programme to check whether a given
 *          number is an ugly number. Ugly numbers are
 *          positive numbers whose prime factors only include 2, 3, 5.
 * Solve: because every number can be represented as product of
 *        some primes. Then delete all the 2, 3, 5 factors, we
 *        will see if it has other prime factor.
 * Tips: negative
 */
class Solution {
    public:
        bool isUgly(int num) {
            if (num <= 0) return false;

            while (num % 2 == 0) num /= 2;
            while (num % 3 == 0) num /= 3;
            while (num % 5 == 0) num /= 5;

            return num == 1;

        }

};
