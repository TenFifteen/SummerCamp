/**
 * Problem:  There is a heap of stones on the table, each time one of
 *           you take turns to remove 1 to 3 stones. The one who removes
 *           the last stone will be the winner. You will take the first
 *           turn to remove the stones.
 * Solve: mod 4
 * Tips: no
 */
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
