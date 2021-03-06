/**
 * Problem: Given an array of integers, find if any array contains
 *          any duplicates.
 * Solve: set
 * Tips: no
 *
 */
class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> hash;
            for(int i = 0; i < nums.size(); ++i) {
                if (hash.find(nums[i]) != hash.end()) {
                    return true;

                }
                hash.insert(nums[i]);

            }
            return false;

        }

};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dict;
        for (int num : nums) {
            if (dict.find(num) != dict.end()) return true;
            dict.insert(num);
        }

        return false;
    }
};
