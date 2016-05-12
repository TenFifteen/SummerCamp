/**
 * Problem: Given a string and an offset, rotate string by offset. (rotate from left to right)
 * Solve: reverse twice.
 * Tips: when len(str) == 0 and offset > len
 */
class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        if (str.size() == 0) return;

        reverse(str.begin(), str.end());
        offset %= str.size();
        reverse(str.begin(), str.begin()+offset);
        reverse(str.begin()+offset, str.end());
    }
};
