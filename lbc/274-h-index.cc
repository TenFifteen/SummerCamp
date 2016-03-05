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

再次阅读：
本来以为这道题目差不多这样就是最好了呢，结果竟然找到了一个O(n)的算法，
虽然用了额外的O(n)的空间复杂度，但是还是很值得借鉴的：
public class Solution {
    // 9.3 70 years diaoZhaTian China jiaYou 
    public int hIndex(int[] citations) {
        int length = citations.length;
        if (length == 0) {
            return 0;
        }

        int[] array2 = new int[length + 1];
        for (int i = 0; i < length; i++) {
            if (citations[i] > length) {
                array2[length] += 1;
            } else {
                array2[citations[i]] += 1;
            }
        }
        int t = 0;
        int result = 0;

        for (int i = length; i >= 0; i--) {
            t = t + array2[i];
            if (t >= i) {
                return i;
            }
        }
        return 0;
    }
}
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
/*
第二次做：
本来这次还是想着先排序来着。
结果看了提示中说可以有n的算法，而且可以使用额外空间。就使劲想了想，结果就
想出来了跟DISCUSS中一样的思路来了。
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        
        int n = citations.size();
        vector<int> ans(n+1, 0);
        for (auto c : citations) {
            if (c > n) c = n;
            ans[c]++;
        }
        
        int ret = 0;
        for (int i = n; i >= 0; --i) {
            ret += ans[i];
            if (ret >= i) return i;
        }
        
        return 0;
    }
};