/**
 * Problem: given an array of numbers range from 0 to 2, sort them so that numbers of the
 *          same value are adjacent, with the values in the order 0, 1, 2
 * Solve: three pointers point to the end of the corresponding numbers
 * Tips: the pointers with bigger value go first
 */
void sortColors(int* nums, int numsSize) {
    int zeros = -1, ones = -1, twos = -1;

    int i;
    for (i = 0; i < numsSize; ++i) {
        switch (nums[i]) {
            case 0:
                // notice the order of assignment
                nums[++twos] = 2;
                nums[++ones] = 1;
                nums[++zeros] = 0;
                break;
            case 1:
                nums[++twos] = 2;
                nums[++ones] = 1;
                break;
            case 2:
                nums[++twos] = 2;
        }
    }
}

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int left = 0, mid = 0, right = nums.size() - 1;

            while (mid <= right) {
                if (nums[mid] == 0) {
                    swap(nums[left++], nums[mid++]);
                } else if (nums[mid] == 2) {
                    swap(nums[right--], nums[mid]);
                } else {
                    ++mid;
                }
            }
        }
};
