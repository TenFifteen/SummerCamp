#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
/**
 * Problem: Given an array of n positive integers and a positive integer s,
 *          find the minimal length of a subarray of which the sum >= s. If
 *          there isn't one, return -1 instead.
 * Solve: partial sum and two pointers.
 * Tips: no
 */
/**
 * @param nums: a vector of integers
 * @param s: an integer
 * @return: an integer representing the minimum size of subarray
 */
int minimumSize(vector<int> &nums, int s) {
    // write your code here
    int n = nums.size();
    if (n == 0) return -1;

    vector<int> partSum(n+1);
    partSum[0] = 0;
    partial_sum(nums.begin(), nums.end(), partSum.begin()+1);

    int ans = INT_MAX;
    int l = 0, r = 1;
    while (l <= r && r <= n) {
        if (partSum[r] - partSum[l] >= s) {
            ans = min(ans, r-l);
            l++;
        } else {
            ++r;
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<int> partSum(nums.size());
    partial_sum(nums.begin(), nums.end(), partSum.begin());

    for (int i = 0; i < partSum.size(); ++i) {
        cout << partSum[i] << endl;
    }

    return 0;
}
