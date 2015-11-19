#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

/**
 * Problem: Given a string S and a string T, find the minimum windows in S
 *          which will contain all the characters in T in complexity O(n);
 * Solve: 1. Use a map to count the times per character occurs in the window
 *           in S.
 *        2. Use two pointers to specify the window.
 *        3. Use the variable need_count to record the needed count of the
 *           character.
 * Tips: 1. str.size() return a unsigned number.
 *       2. The right pointer must represent the right frontier of the window
 *          instead plus extra one.
 */
string minWindow(string s, string t)
{
    if (s.size() == 0 || t.size() == 0) return "";


    bool in_template[128] = {false};
    //  count for every character in the string of the window specified by the two pointer
    //  initialized to opposite number of count per character in string t;
    int char_count[128] = {0};
    for (int i = 0; i < t.size(); ++i) {
        --char_count[t[i]];
        in_template[t[i]] = true;
    }

    int left = 0, right = -1;
    int min_size =  INT_MAX, min_index = -1;
    int need_count = t.size();

    while (left < (int)s.size() && right < (int)s.size()) {
        if (need_count == 0) { // slide the left pointer
            if (right-left+1 < min_size) {
                min_size = right - left + 1;
                min_index = left;
            }

            --char_count[s[left]];
            if (in_template[s[left]] && char_count[s[left]] < 0) ++need_count;
            ++left;
        } else { // slide the right pointer
            ++right;
            ++char_count[s[right]];
            if (in_template[s[right]] && char_count[s[right]] <= 0) --need_count;
        }
    }

    if (min_size == INT_MAX) return "";
    return s.substr(min_index, min_size);
}
int main()
{
    string s, t;
    while (cin >> s >> t) {
         cout << minWindow(s, t) << endl;
    }

    return 0;
}
