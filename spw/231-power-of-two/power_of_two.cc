/**
 * Problem: Given a integer, write a function to determine
 *          if it is power of two.
 * Solve: elimate the rightmost of 1 using bit operation, then
 *        judge if the result is equal to 0.
 * Tips: Consider the special case: 0 and INT_MIN
 */
class Solution {
    public:
        bool isPowerOfTwo(int n) {
            if (n == 0 || n == INT_MIN) return false;
            if ( (n & (n-1)) == 0 )
                return true;
            return false;

        }

};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};
