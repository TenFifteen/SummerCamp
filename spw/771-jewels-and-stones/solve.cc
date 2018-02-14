/**
 * Problem: You're given strings J representing the types of
 *          stones that are jewels, and S representing the stones
 *          you have.  Each character in S is a type of stone you have.
 *          You want to know how many of the stones you have are also jewels.
 *
 *          The letters in J are guaranteed distinct, and all characters
 *          in J and S are letters. Letters are case sensitive, so "a"
 *          is considered a different type of stone from "A".
 * Solve: just do it
 * Tips: no
 */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool jewels[256] = {false};
        for (auto& c : J) jewels[c] = true;

        int cnt = 0;
        for (auto &c : S)
            if (jewels[c])
                ++cnt;

        return cnt;
    }
};
