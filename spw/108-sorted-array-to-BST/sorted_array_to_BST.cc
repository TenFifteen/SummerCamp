TreeNode* dfs(vector<int> &nums, int left, int right) {
	if (left > right) return NULL;

	int mid = (left + right) / 2;
	TreeNode *now_root = new TreeNode(nums[mid]);
	now_root->left = dfs(nums, left, mid-1);
	now_root->right = dfs(nums, mid+1, right);
}

/**
 * Problem: Given an array where elements are sorted in ascending order,
 *          convert it to a height balanced BST.
 * Solve: recursive:mid
 * Tips: none
 */
TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.empty()) return NULL;

	return dfs(nums, 0, nums.size()-1);
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return sub(nums, 0, n-1);
    }

    TreeNode *sub(vector<int> &nums, int left, int right) {
        if (left > right) return NULL;

        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = sub(nums, left, mid-1);
        root->right = sub(nums, mid+1, right);

        return root;
    }
};
