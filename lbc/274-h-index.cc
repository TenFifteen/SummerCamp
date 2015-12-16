/*
题目大意：
给定一个科学家每篇文章的引用数量。每个科学家的H值计算方式是：
如果有H篇文章的引用数量大于等于H，那么就是该科学家的H值。
取其中合理的值中的最大值。

解题思路：
将所有引用排序，然后从后往前搜索。
复杂度就是排序复杂度。

遇到的问题：
没有问题。
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int n = citations.size();
        for (int i = n; i > 0; --i) {
            if (citations[n-i] >= i) {
                return i;
            }
        }
        
        return 0;
    }
};