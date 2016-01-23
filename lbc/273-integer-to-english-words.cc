/*
题目大意：
给定一个数字，然后将其转化为其读音的字符串表示。

解题思路：
直接按照读英文的过程将其一步步转化即可。

遇到的问题：
没有问题。

再次阅读：
感觉就是一个考验编程的题目，没有太多技巧。
但是之前的代码还是有点过分了哈，可以参考一下人家的稍微简洁一些的代码：
class Solution {
public:
    static string numberToWords(int n) {
        if(n == 0) return "Zero";
        else return int_string(n).substr(1);
    }
private:
    static const char * const below_20[];
    static const char * const below_100[];
    static string int_string(int n) {
        if(n >= 1000000000)   return int_string(n / 1000000000) + " Billion" + int_string(n - 1000000000 * (n / 1000000000));
        else if(n >= 1000000) return int_string(n / 1000000) + " Million" + int_string(n - 1000000 * (n / 1000000));
        else if(n >= 1000)    return int_string(n / 1000) + " Thousand" + int_string(n - 1000 * (n / 1000));
        else if(n >= 100)     return int_string(n / 100) + " Hundred" + int_string(n - 100 * (n / 100));
        else if(n >= 20)      return string(" ") + below_100[n / 10 - 2] + int_string(n - 10 * (n / 10));
        else if(n >= 1)       return string(" ") + below_20[n - 1];
        else return "";
        }
    }
};

const char * const Solution::below_20[] =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const char * const Solution::below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
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