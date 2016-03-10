/*
题目大意：
给定一个target字符串，问在source字符串的所有字串中，能够将target中的字母覆盖的最短的字串是什么？

解题思路：
hash + 卡尺法

遇到的问题：
将right++写错地方了。
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
        unordered_map<char, int> hash;
        for (auto ch : target) {
            hash[ch]++;
        }
        
        unordered_map<char, int> now;
        int ans_start, ans_len = INT_MAX, total = 0, left = 0, right = 0;
        while (right < source.size()) {
            while (total < target.size() && right < source.size()) {
                if (hash.find(source[right]) != hash.end()) {
                    now[source[right]]++;
                    if (now[source[right]] <= hash[source[right]]) total++;
                }
                right++;
            }
            while (total >= target.size()) {
                if (right-left < ans_len) {
                    ans_start = left;
                    ans_len = right-left;
                }
                if (hash.find(source[left]) != hash.end()) {
                    now[source[left]]--;
                    if (now[source[left]] < hash[source[left]]) total--;
                }
                left++;
            }
        }
        
        return ans_len == INT_MAX ? "" : source.substr(ans_start, ans_len);
    }
};
