/**
 * Problem: Given an array nums, write a function to move
 *          all 0's to the end of it while maintaining the
 *          relative order of the non-zero elements.
 * Solve: Iterator.
 * Tips: no
 */
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int pos = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i]) {
                    nums[pos++] = nums[i];

                }

            }

            while (pos < nums.size()) {
                nums[pos++] = 0;

            }

        }

};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[pos++] = nums[i];
            }
        }

        while (pos < nums.size()) nums[pos++] = 0;
    }
};
