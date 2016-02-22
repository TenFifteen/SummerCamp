/*
题目大意：
跟274是一样的，但是这次的输入本身就是有序的。

解题思路：
跟274一样，但是不需要排序了。

遇到的问题：
没有问题。

再次阅读：
虽然感觉可以二分搜索，但是总是觉得二分不能处理有多个可行解的情况。所以没敢用，
但是看到DISCUSS中最好的解法就是用的最传统的二分搜索：
再想想，他这种二分是可以处理有多个可行解的情形的。
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left=0, len = citations.size(), right= len-1,  mid;
        while(left<=right)
        {
            mid=(left+right)>>1;
            if(citations[mid]== (len-mid)) return citations[mid];
            else if(citations[mid] > (len-mid)) right = mid - 1;
            else left = mid + 1;
        }
        return len - (right+1);
    }
};
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for (int i = n; i > 0; --i) {
            if (citations[n-i] >= i) {
                return i;
            }
        }
        
        return 0;
    }
};