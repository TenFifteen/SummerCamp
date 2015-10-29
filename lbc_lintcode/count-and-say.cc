/*
题目：26 % 报数 容易

题目大意：
一次数出字符串中的各个digit

解题思路：
直接数

遇到的问题：
没有问题。
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
        string ret = "1";
        for (int i = 1; i < n; ++i) {
            string next;
            int last = 0;
            while (last < ret.size()) {
                int cur = last;
                while (cur < ret.size() && ret[cur] == ret[last]) {
                    cur++;
                }
                next.append(to_string(cur-last));
                next.append(ret.substr(last, 1));
                last = cur;
            }
            ret.swap(next);
        }
        return ret;
    }
};
