/*
题目大意：
给定一个数组，一系列的查询，问有多少个数小于某个数

解题思路：
排序，二分

遇到的问题：
没有。
*/
class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        sort(A.begin(), A.end());
        
        vector<int> ans(queries.size(), 0);
        if (A.size() == 0) return ans;
        
        for (int i = 0; i < queries.size(); ++i) {
            int left = 0, right = A.size()-1;
            while (left < right) {
                int mid = (left+right)>>1;
                if (A[mid] < queries[i]) left = mid+1;
                else right = mid;
            }
            if (A[left] >= queries[i]) ans[i] = left;
            else ans[i] = left+1;
        }
        return ans;
    }
};