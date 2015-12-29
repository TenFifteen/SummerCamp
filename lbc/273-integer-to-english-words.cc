/*
题目大意：
给定一个数字，然后将其转化为其读音的字符串表示。

解题思路：
直接按照读英文的过程将其一步步转化即可。

遇到的问题：
没有问题。
*/
class Solution {
public:
    string numberToWords(int num) {
        static unordered_map<int, string> trans = {
            {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"},
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
            {20, "Twenty"},
            {30, "Thirty"},
            {40, "Forty"},
            {50, "Fifty"},
            {60, "Sixty"},
            {70, "Seventy"},
            {80, "Eighty"},
            {90, "Ninety"}
        };
        
        if (num == 0) {
            return "Zero";
        }
        
        vector<string> ans;
        if (num >= 1000000000) {
            int cur = num/1000000000;
            num %= 1000000000;
            if (cur >= 20) {
                ans.push_back(trans[cur/10*10]);
                cur %= 10;
            }
            if (cur != 0) {
                ans.push_back(trans[cur]);
            }
            ans.push_back("Billion");
        }
        
        if (num >= 1000000) {
            int cur = num/1000000;
            num %= 1000000;
            if (cur >= 100) {
                ans.push_back(trans[cur/100]);
                ans.push_back("Hundred");
                cur %= 100;
            }
            if (cur >= 20) {
                ans.push_back(trans[cur/10*10]);
                cur %= 10;
            }
            if (cur != 0) {
                ans.push_back(trans[cur]);
            }
            ans.push_back("Million");
        }
        
        if (num >= 1000) {
            int cur = num/1000;
            num %= 1000;
            if (cur >= 100) {
                ans.push_back(trans[cur/100]);
                ans.push_back("Hundred");
                cur %= 100;
            }
            if (cur >= 20) {
                ans.push_back(trans[cur/10*10]);
                cur %= 10;
            }
            if (cur != 0) {
                ans.push_back(trans[cur]);
            }
            ans.push_back("Thousand");
        }
        
        if (num) {
            int cur = num;
            if (cur >= 100) {
                ans.push_back(trans[cur/100]);
                ans.push_back("Hundred");
                cur %= 100;
            }
            if (cur >= 20) {
                ans.push_back(trans[cur/10*10]);
                cur %= 10;
            }
            if (cur != 0) {
                ans.push_back(trans[cur]);
            }
        }
        
        string ret = ans[0];
        for (int i = 1; i < ans.size(); ++i) {
            ret += " ";
            ret += ans[i];
        }
        
        return ret;
    }
};