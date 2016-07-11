/**
 * Problem: if duplicates are allowed, search in rotated sorted array.
 * Solve: use nums[mid] with nums[left] or nums[right] to identify where the
 *        interval the mid is in. Note that there are two possible cases when
 *        they are equal.
 *  Tips: see above
 */
bool search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target) {
            if (nums[mid] > nums[right]) {
                if (nums[right] > target) left = mid + 1;
                else if (nums[right] < target) right = mid - 1;
                else return true;

            } else if (nums[mid] < nums[right]){
                right = mid -1;

            } else {
                --right;

            }

        } else if (nums[mid] < target) {
            if (nums[mid] < nums[left]) {
                if (nums[left] < target) right = mid - 1;
                else if (nums[left] > target) left = mid + 1;
                else return true;

            } else if (nums[mid] > nums[left]){
                left = mid + 1;

            } else {
                ++left;

            }

        } else {
            return true;

        }

    }
    return false;

}

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (nums[mid] == target) return true;
                // partition the mid first, then we can find a continuous section.
                // if the target is in this section, then discard the other section.
                // retain otherwise.
                //
                // tips: we can all skip mid, because we consider nums[mid]  first.
                if (nums[mid] > nums[right]) {
                    if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                    else left = mid + 1;
                } else if (nums[mid] < nums[right]) {
                    if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                    else right = mid - 1;
                } else {
                    //  in this case, we can't find a section like above, then just
                    //  skip the nums[right] == nums[mid] != target
                    --right;
                }
            }

            return false;
        }
};
