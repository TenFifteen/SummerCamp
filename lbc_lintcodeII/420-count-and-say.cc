/*
题目大意：
数数字，然后输出。输出第n个序列。

解题思路：
直接数

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        if (n < 1) return "";
        
        string ans = "1";
        for (int i = 1; i < n; ++i) {
            string next;
            int end = 0, front = 1;
            while (end < ans.size()) {
                while (front < ans.size() && ans[front] == ans[end]) front++;
                next += to_string(front-end);
                next += ans[end];
                end = front;
            }
            
            ans = next;
        }
        
        return ans;
    }
};