/**
 * Problem: Numbers keep coming, return the median of numbers at every time a new number added.
 * Solve: a big heap and small heap
 * Tips: no
 */
class Solution {
    public:
        class Cmp {
            public:
                bool operator() (int a, int b) {
                    return a > b;
                }
        };

        /**
         * @param nums: A list of integers.
         * @return: The median of numbers
         */
        vector<int> medianII(vector<int> &nums) {
            priority_queue<int> left;
            priority_queue<int, vector<int>, Cmp> right;

            vector<int> ans;
            int n = nums.size();
            for (int i = 0; i < n; ++i) {

                if (left.empty() || nums[i] <= left.top()) left.push(nums[i]);
                else right.push(nums[i]);

                if (left.size() > right.size()+1) {
                    right.push(left.top());
                    left.pop();
                } else if (left.size() < right.size()) {
                    left.push(right.top());
                    right.pop();
                }

                ans.push_back(left.top());
            }

            return ans;
        }
};

