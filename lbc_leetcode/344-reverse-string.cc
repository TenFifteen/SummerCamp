/*
 * too easy
 */
class Solution {
public:
    string reverseString(string s) {
        if (s.size() < 2) return s;
        int left = 0, right = s.size()-1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
