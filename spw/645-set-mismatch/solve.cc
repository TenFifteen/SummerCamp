/**
 * Problem: The set S originally contains numbers from 1 to n. But unfortunately,
 *          due to the data error, one of the numbers in the set got duplicated to
 *          another number in the set, which results in repetition of one number
 *          and loss of another number.
 *          Given an array nums representing the data status of this set after the
 *          error. Your task is to firstly find the number occurs twice and then
 *          find the number that is missing. Return them in the form of an array.
 * Solve: a. Find the now number nums[pos]
 *        b. Find its right place nums[pos]-1
 *        c. Test if the place have the right number.
 *        d. If right, then this(nums[pos]) is a redundant number, but pos+1 may not
 *           be the missing number, because there are still other numbers not in the
 *           right place.
 * Tips: no
 */
ass Solution {
    public:
        vector<int> findErrorNums(vector<int>& nums) {
            vector<int> res(2);

            int pos = 0, n = nums.size();
            while (pos < n) {
                int j = pos;
                while (nums[nums[j]-1] != nums[j]) {
                    swap(nums[j], nums[nums[j]-1]);
                }

                if (nums[pos] != pos+1) {
                    res[0] = nums[nums[pos]-1];
                    res[1] = pos+1;
                }
                ++pos;
            }

            return res;
        }
};
