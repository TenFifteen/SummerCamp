/*
题目大意：
给定一个数组，有重复数字。求其所有的子集

解题思路：
第一次用迭代式。

遇到的问题：
注意dup数组的使用。
*/
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<int> arr(S.begin(), S.end());
        sort(arr.begin(), arr.end());
        
        vector<int> dup(arr.size(), 1);
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] == arr[i-1]) dup[i] = dup[i-1]+1;
        }
        
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        
        for (int i = 0; i < arr.size(); ++i) {
            int len = ans.size();
            for (int j = 0; j < len; ++j) {
                if ((i != 0 && arr[i] == arr[i-1]) 
                    && (ans[j].size() < dup[i]-1 || ans[j][ans[j].size()+1-dup[i]] != arr[i])) continue;
                vector<int> cur = ans[j];
                cur.push_back(arr[i]);
                ans.push_back(cur);
            }
        }
        
        return ans;
    }
};
