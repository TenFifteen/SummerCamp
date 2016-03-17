/*
题目大意：
给定一个数组，问其中最长的连续数字的长度是多少？

解题思路：
hash记录区间

遇到的问题：
一开始没有写hash[n] = len；这句话，这句话还是非常重要的，用来指示下一次遇到这个数字不用处理了。
结果一开始自作聪明的没有写，结果悲剧了好久，最后才想出来是这里的问题。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        unordered_map<int, int> hash;
        
        int ans = 0;
        
        for (auto n : num) {
            if (hash[n] != 0) continue;
            
            int len = hash[n-1]+hash[n+1]+1;
            hash[n-hash[n-1]] = len;
            hash[n+hash[n+1]] = len;
            hash[n] = len;
            ans = max(ans, len);
        }
        
        return ans;
    }
};