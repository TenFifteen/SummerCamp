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
