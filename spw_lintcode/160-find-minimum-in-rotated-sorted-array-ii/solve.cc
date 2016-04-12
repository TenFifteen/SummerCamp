/**
 * Problem: Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *          Find the minimum element.
 *          The array may contain duplicates.
 * Solve: use binary search, but if there are too many equivalent elements, the time
 *        complexity may go bad to O(n)
 * Tips: see comment below.
 */
class Solution {
    public:
        /**
         * @param num: the rotated sorted array
         * @return: the minimum number in the array
         */
        int findMin(vector<int> &num) {
            int left = 0, right = num.size()-1;

            while (left < right) {
                int mid = left + (right - left) / 2;

                if (num[mid] < num[right]) {
                    /*this because we find the minimum, then we should not miss the smaller one
                     *then we will not let the right = mid-1 which will probably miss it*/
                    right = mid;
                } else if (num[mid] > num[right]){
                    /* because nums[mid] is certainly not the smallest one, that is, the right one
                     must be bigger than it, then we can skip it.*/
                    left = mid + 1;
                    /*because the right-1 is big or equal than mid(in the condition that left < right)*/
                } else {
                    --right;
                }
            }

            return num[left];
        }
};

/**
 * This one has some problem.
 */
int findMin(vector<int> &num) {
    int left = 0, right = num.size()-1;

    while (left < right) {
        int mid = (right + left) / 2;

        if (num[mid] > num[left]) {
            left = mid + 1;

        } else if (num[mid] < num[left]){
            right = mid;

        } else {
            // left may == mid
            // Then the operation will probably skip the smallest one
            // this has association with the mid = (left + right) / 2
            // has been round down
            ++left;
        }

    }

    return num[left];

}
