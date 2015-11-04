/*
题目：12 % nuts 和 bolts 的问题 中等

题目大意：
给定一堆螺母和一堆螺钉。给一个函数，可以比较给定的一个螺母和一个螺钉。并且可以
比出大小或者相等。然后螺钉和螺钉、螺母和螺母之间是不能进行比较的。
将两者进行排序，使之一一对应。

解题思路：
快排的思路。

遇到的问题：
没有太大问题。
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
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        if (nuts.size() == 0) return;
        sub(nuts, bolts, 0, nuts.size()-1, compare);
    }
    
    void sub(vector<string> &nuts, vector<string> &bolts, int left, int right, Comparator &compare) {
        if (left >= right) return;
        int bleft = left, bright = right;
        while (bleft < bright) {
            while (bleft < bright && compare.cmp(nuts[left], bolts[bleft]) > 0) bleft++;
            while (bleft < bright && compare.cmp(nuts[left], bolts[bright]) < 0) bright--;
            swap(bolts[bleft], bolts[bright]);
        }
        int nleft = left, nright = right;
        while (nleft < nright) {
            while (nleft < nright && compare.cmp(nuts[nleft], bolts[bleft]) < 0) nleft++;
            while (nleft < nright && compare.cmp(nuts[nright], bolts[bleft]) > 0) nright--;
            swap(nuts[nleft], nuts[nright]);
        }
        sub(nuts, bolts, left, nleft-1, compare);
        sub(nuts, bolts, nleft+1, right, compare);
    }
};
