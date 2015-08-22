/*
题目：20 % 最小子串覆盖 中等

题目大意：
给定一个target字符串，问在source的所有字串中，能够包含所有的target字符的最短的字串是啥？

解题思路：
用两个指针代表当前的区间，然后用一个map来记录所有的字符的个数。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        if (source.size() < target.size()) return "";
        int front = 0, end = 0;
        unordered_map<char, int> cnt;
        for (auto ch : target) {
            cnt[ch]++;
        }
        int ans, len = INT_MAX;
        while (front < source.size()) {
            while (front < source.size() && !isFinish(cnt)) {
                if (cnt.find(source[front]) != cnt.end()) {
                    cnt[source[front]]--;
                }
                front++;
            }
            if (!isFinish(cnt)) {
                break;
            } else {
                while (isFinish(cnt)) {
                    if (front-end < len) {
                        len = front-end;
                        ans = end;
                    }
                    if (cnt.find(source[end]) != cnt.end()) {
                        cnt[source[end]]++;
                    }
                    end++;
                }
            }
        }
        if (len == INT_MAX) {
            return "";
        } else {
            return source.substr(ans, len);
        }
    }

    bool isFinish(unordered_map<char, int> &cnt) {
        for (auto c : cnt) {
            if (c.second > 0) return false;
        }
        return true;
    }
};

