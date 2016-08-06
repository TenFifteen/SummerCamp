/*
 * ok
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 1 || (num & (num-1))) return false;
        return num & 0x55555555;
    }
};
