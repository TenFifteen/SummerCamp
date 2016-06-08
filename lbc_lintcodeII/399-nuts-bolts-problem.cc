/*
题目大意：
给定一堆螺丝和螺母，都是一一对应的，现在给他们排序。

解题思路：
快排思路。

遇到的问题：
没有。竟然一次通过了。
*/
/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
    void _sort(vector<string> &nuts, vector<string> &bolts, int left, int right, Comparator &cmp) {
        if (left >= right) return;
        
        int i = left, j = left, k = right;
        while (j <= k) {
            if (cmp.cmp(nuts[left], bolts[j]) < 0) {
                swap(bolts[j], bolts[k--]);
            } else if (cmp.cmp(nuts[left], bolts[j]) == 0) {
                j++;
            } else {
                swap(bolts[j++], bolts[i++]);
            }
        }
        
        int index = i;
        i = left, j = left, k = right;
        while (j <= k) {
            if (cmp.cmp(nuts[j], bolts[index]) > 0) {
                swap(nuts[j], nuts[k--]);
            } else if (cmp.cmp(nuts[j], bolts[index]) == 0) {
                j++;
            } else {
                swap(nuts[j++], nuts[i++]);
            }
        }
        
        _sort(nuts, bolts, left, index-1, cmp);
        _sort(nuts, bolts, index+1, right, cmp);
    }
    
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        if (nuts.size() == 0 || nuts.size() != bolts.size()) return;
        _sort(nuts, bolts, 0, nuts.size()-1, compare);
    }
};
