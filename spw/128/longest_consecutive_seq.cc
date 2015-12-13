#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/**
 * Problem: Given an unsorted array of integers, find the length of longest consecutive elements
 *          sequence.
 * Solve: Copied from the clipboard. The basic idea is use a map to trace the element of consecutive
 *        sequence border to the consecutive length.
 * Tips: see bellow.
 */
int longestConsecutive(vector<int>& nums)
{
    unordered_map<int, int> index_len;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if(index_len.find(nums[i]) == index_len.end()) {
            int left_len = index_len.find(nums[i]-1) == index_len.end() ? 0 : index_len[nums[i]-1];
            int right_len = index_len.find(nums[i]+1) == index_len.end() ? 0 : index_len[nums[i]+1];

            int sum_len = left_len + right_len + 1;
            // this is only for skip the duplicates in the next time
            // and it will matter when the left_len and right_len are all not zero
            index_len[nums[i]] = sum_len;

            index_len[nums[i]-left_len] = sum_len;
            index_len[nums[i]+right_len] = sum_len;

            res = sum_len > res ? sum_len : res;

        }

    }

    return res;

}
int main()
{
    vector<int> nums;
    int c, num;
    while (cin >> c) {
        while (c--) {
            cin >> num;
            nums.push_back(num);
        }
        cout << longestConsecutive(nums) << endl;
        nums.clear();
    }

    return 0;
}
