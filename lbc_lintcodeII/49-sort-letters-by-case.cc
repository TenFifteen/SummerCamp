/*
题目大意：
给定一个字符串，按照小写在前大写在后的方式排序。

解题思路：
两个指针。

遇到的问题：
没有。
*/
class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        if (letters.size() < 2) return;
        
        #define lower(ch) ((ch) >= 'a' && (ch) <= 'z')
        #define upper(ch) ((ch) >= 'A' && (ch) <= 'Z')
        
        int left = 0, right = letters.size()-1;
        while (left < right) {
            while (left < right && lower(letters[left])) left++;
            while (left < right && upper(letters[right])) right--;
            swap(letters[left], letters[right]);
        }
    }
};
