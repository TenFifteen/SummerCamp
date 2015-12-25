/*
题目大意：
给定一个数组，求其中的某一段区间的和。
查询操作可能有很多次。而且中间数组也不会变。

解题思路：
将数组的前缀和算出来，求和的时候直接做减法就行了。

遇到的问题：
没有问题。
*/
class NumArray {
    vector<long long> ans;
public:
    NumArray(vector<int> &nums) {
        if (nums.size() == 0) return;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            int next = ans[ans.size()-1] + nums[i];
            ans.push_back(next);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return ans[j];
        }
        return ans[j] - ans[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);