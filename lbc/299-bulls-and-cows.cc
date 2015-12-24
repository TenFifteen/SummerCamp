/*
题目大意：
给定两个数字。其中位置相同数字相同的，就是bull的数量。
位置不同，数字相同的，叫做cows。
求这两个值。

解题思路：
bull的值可以直接遍历就可以了。
cows的值需要一个hash来做中间存储。

遇到的问题：
没有问题。
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int len = min(secret.size(), guess.size());
        for (int i = 0; i < len; ++i) {
            if (secret[i] == guess[i]) bull++;
        }
        
        map<char, int> m;
        for (int i = 0; i < secret.size(); ++i) {
            if (i >= guess.size() || secret[i] != guess[i]) {
                m[secret[i]]++;
            }
        }
        
        int cows = 0;
        for (int i = 0; i < guess.size(); ++i) {
            if (i >= secret.size() || secret[i] != guess[i]) {
                if (--m[guess[i]] >= 0) {
                    cows++;
                }
            }
        }
        
        return to_string(bull) + "A" + to_string(cows) + "B";
    }
};