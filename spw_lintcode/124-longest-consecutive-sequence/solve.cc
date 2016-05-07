/**
 * Problem: Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * Solve: Use a hash map, to keep the two boundary and its len.
 * Tips: notice that a long interval must be merged one by one by a single number.
 *       And every time, we merge two intervals, we use a number and see its left and right of difference of 1.
 *       That is to say, if the number has been considered, we need not consider it. If it has been considered
 *       we have to mark it in the map.
 */
class Solution {
    public:
        /**
         * @param nums: A list of integers
         * @return an integer
         */
        int longestConsecutive(vector<int> &num) {
            unordered_map<int, int> index_len;

            int n = num.size();
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                // only and must only consider the one beside the existing interval.
                if (index_len.find(num[i]) == index_len.end()) {
                    int left_len = index_len.find(num[i]-1) == index_len.end() ? 0 : index_len[num[i]-1];
                    int right_len = index_len.find(num[i]+1) == index_len.end() ? 0 : index_len[num[i]+1];

                    int total_len = left_len + 1 + right_len;

                    index_len[num[i]-left_len] = index_len[num[i]+right_len] = total_len;

                    // when left_len != 0 && right_len != 0, we must mark 'nums[i]' has been used.
                    index_len[num[i]] = total_len;

                    ans = max(ans, total_len);
                }
            }

            return ans;
        }
};
