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
