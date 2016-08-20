/*
 * not too hard.
 */
class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'; // easy to forget Upper case.
    }

public:
    string reverseVowels(string s) {
        if (s.size() < 2) return s;
        int left = 0, right = s.size();
        while (left < right) {
            while (left < right && !isVowel(s[left])) left++;
            while (left < right && !isVowel(s[right])) right--;
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
