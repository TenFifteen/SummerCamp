/*
题目大意：
给定一个数组，表示每本书有多少页。然后有k个抄写员，每个人都要
抄写连续的书。如果每个人抄写的速度是一样的，那么最多需要抄写多久？

集体思路：
二分。。。

遇到的问题：
原来好像是一个很难的动规，还需要做什么优化的来着。这次突然想到了二分
好像也可以，就试了一下，竟然是可以的。
*/
class Solution {
    bool satisfy(const vector<int> &pages, int k, int ans) {
        int index = 0;
        while (k > 0 && index < pages.size()) {
            int cur = pages[index++];
            while (cur <= ans && index < pages.size()) {
                cur += pages[index++];
            }
            k--;
            if (cur > ans) index--;
        }
        
        return index == pages.size();
    }
    
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int left = 1, right = INT_MAX;
        
        while (left < right) {
            int mid = (right-left)/2 + left;
            
            if (satisfy(pages, k, mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        
        return left;
    }
};
