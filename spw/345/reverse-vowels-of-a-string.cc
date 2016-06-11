/**
 * Problem: Write a function that takes a string as input and reverse only the vowels of a string.
 * Solve: remember the position of every vowels and reverse then
 * Tips: use static dict
 */
class Solution {
    public:
        string reverseVowels(string s) {
            static bool dict[256] = {false};
            static bool init = false;
            if (!init) {
                dict['a'] = dict['e'] = dict['i'] = dict['o'] = dict['u'] = true;
                dict['A'] = dict['E'] = dict['I'] = dict['O'] = dict['U'] = true;
                init = true;
            }

            int len = s.size();


            vector<int> pos;
            for (int i = 0; i < len; ++i) {
                if (dict[s[i]]) {
                    pos.push_back(i);
                }
            }

            int n = pos.size();
            int half = n / 2;
            for (int i = 0; i < half; ++i) {
                swap(s[pos[i]], s[pos[n-i-1]]);
            }

            return s;
        }
};
