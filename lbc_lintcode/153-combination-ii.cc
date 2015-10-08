/*
题目：26 % 数字组合 II 中等

题目大意：
给定一个乱序的有重复的数组。问有哪些组合可以加和为target。

解题思路：
按层遍历，每层放一边每个数

遇到的问题：
竟然没有写出来，还是参考的原来的代码。
看来这种题目，我还是没有理解透彻啊。
*/
class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        if (num.size() == 0) return ans;
        vector<int> cur;
        sub(ans, num, target, 0, cur);
        return ans;
    }
    
    void sub(vector<vector<int>> &ans, vector<int> &num, int target, int index, vector<int> &cur) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (target < 0 || index >= num.size()) return;
        for (int i = index; i < num.size(); ++i) {
            if (i != index && num[i] == num[i-1]) continue;
            cur.push_back(num[i]);
            sub(ans, num, target-num[i], i+1, cur);
            cur.pop_back();
        }
    }
};
