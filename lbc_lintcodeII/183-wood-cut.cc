/*
题目大意：
给定一组木头，让切出大于等于ｋ条一样长的木块来。
求最长可以切多长？

解题思路：
二分

遇到的问题：
没有太大问题。不过还是把left，right搞反了。
*/
class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        int maxLen = 0;
        for (auto l : L) maxLen = max(maxLen, l);
        
        long long left = 0, right = maxLen;
        while (left < right) {
            long long mid = (left+right+1)/2;
            
            long long total = 0;
            for (auto l : L) {
                total += l/mid;
            }
            
            if (total >= k) {
                left = mid;
            } else {
                right = mid-1;
            }
        }
        
        return left;
    }
};
