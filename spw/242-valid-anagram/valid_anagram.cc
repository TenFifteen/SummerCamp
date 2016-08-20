#include <iostream>

using namespace std;

/**
 * Problem: Given two strings s and t, write a function to
 *          determine if t is an anagram of s.
 * Solve: sort or hash
 * Tips: no
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s == t) return true;
        int m = s.size();
        int n = t.size();

        if (m != n) return false;

        unordered_map<char, int> count;
        for (int i = 0; i < m; ++i) {
            count[s[i]]++;
        }
        for (int i = 0; i < m; ++i) {
            count[t[i]]--;
        }
        for (int i = 0; i < m; ++i) {
            if (count[t[i]] != 0) return false;
        }

        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        int table[26] = {0};
        int m = s.size(), n = t.size();
        if (m != n) return false;

        for (int i = 0; i < m; ++i) {
            table[s[i]-'a']++;
            table[t[i]-'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (table[i]) return false;
        }

        return true;
    }
};
