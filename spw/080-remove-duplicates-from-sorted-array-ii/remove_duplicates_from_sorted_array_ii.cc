/**
 * Problem: given an sorted array, the duplicates are allowed at most
 *          twice.
 * Solve: use a new pointer to keep the new array.
 * Tips: the array is sorted
 */
int removeDuplicates(vector<int>& nums) {
    int pos = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i < 2 || nums[pos-2] < nums[i]) {
            nums[pos++] = nums[i];

        }

    }
    return pos;

}

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int i = 0, n = nums.size(), pos = 0;
            while (i < n) {
                nums[pos++] = nums[i++];

                if (i < n && nums[i] == nums[i-1]) {
                    nums[pos++] = nums[i++];
                }

                while (i < n && nums[i] == nums[i-1]) ++i;
            }

            return pos;
        }
};
