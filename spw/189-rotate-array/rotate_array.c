/*C*/
void reverse(int *nums, int left, int right) {
	while (left < right) {
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;

		++left;
		--right;
	}
}
/**
 * Problem: shift an array by k steps.
 * Solve: shift can be implemented by some times of reverse in the
 *        right place.
 * Tips: no
 */
void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;
	if (k == 0) return;

	reverse(nums, 0, numsSize-1);
	reverse(nums, 0, k-1);
	reverse(nums, k, numsSize-1);
}

/*C++*/
void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> ans(n);

	k %= n;
	int left = n - k;
	if (left > n-1  || left < 0) return;
	int count = 0;
	for (int i = left; count != n; i=(i+1)%n, count++) {
		ans[count] = nums[i];
	}
	nums = ans;
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
