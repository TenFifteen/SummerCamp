/*
 * ok.
 * there is a very interesting answer in discuss:
 * https://discuss.leetcode.com/topic/49325/a-square-number-is-1-3-5-7-java-code
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num < 2) return true;

        int left = 0, right = num;
        while (left < right) {
            int mid = left + (right-left) / 2;
            if ((right-left) & 0x1) mid++;
            if (mid <= num/mid) left = mid;
            else right = mid-1;
        }

        return left*left == num;
    }
};
