/*
题目大意：
跟274是一样的，但是这次的输入本身就是有序的。

解题思路：
跟274一样，但是不需要排序了。

遇到的问题：
没有问题。
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