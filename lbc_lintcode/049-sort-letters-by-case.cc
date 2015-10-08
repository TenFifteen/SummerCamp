/*
题目：37 % 字符大小写排序 中等

题目大意：
给定一个只包含大小写字母的字符串，将其所有的小写字母都放在字符串的左边，大写字母放到右边。

解题思路：
两个指针

遇到的问题：
竟然在里面的小循环中将条件写成了left <= right，结果导致错误
*/
class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        if (letters.size() == 0) return;
        int left = 0, right = letters.size()-1;
        while (left <= right) {
            while (left < right && letters[left] >= 'a' && letters[left] <= 'z') left++;
            while (left < right && letters[right] >= 'A' && letters[right] <= 'Z') right--;
            swap(letters[left++], letters[right--]);
        }
    }
};

