#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) return;

    int last = n - 1;
    while (last > 0 && nums[last-1] >= nums[last]) --last;

    if (last == 0) {
        reverse(nums.begin(), nums.end());
        return;

    }

    for (int i = n-1; i >= last; --i) {
        if (nums[i] > nums[last-1]) {
            swap(nums[i], nums[last-1]);
            break;
        }

    }
    sort(nums.begin()+last, nums.end());

}

int main()
{
    int arr[] = {1, 2, 3, 4, 9, 7, 6 ,3, 1};
    vector<int> input(arr, arr+9);

    nextPermutation(input);

    return 0;
}
