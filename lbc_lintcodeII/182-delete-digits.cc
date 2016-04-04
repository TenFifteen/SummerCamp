/*
题目大意：
给定一个string， 表示一个数字，现在要删除k个字符，使得剩下的数字最小。

解题思路：
stack的思路。

遇到的问题：
就是忘记了最后那两个while了。
*/
class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        int n = A.size();
        string ans;
        if (k == n) return ans;
        
        for (int i = 0; i < n; ++i) {
            while (ans.size() > 0 && i-ans.size() < k && A[i] < ans.back()) ans.pop_back();
            ans.push_back(A[i]);
        }
        
        while (ans.size() > n-k) ans.pop_back();
        
        int index = 0;
        while (index < ans.size() && ans[index] == '0') index++;
        
        if (index == ans.size()) return "0";
        return ans.substr(index);
    }
};
