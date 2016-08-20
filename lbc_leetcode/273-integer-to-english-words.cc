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
/*
第二次做：
代码问题不大。
不过有两个问题需要注意，
第一，两个常量字符串不可以直接相加。比如 " " + "Hundred"
第二， 注意题目中出现的0， 中间结果的0不需要翻译。
*/
class Solution {
private:
    unordered_map<int, string> m;

    string count(int n) {
        string ans;
        if (n >= 100) {
            ans += " " + m[n/100];
            ans += " Hundred";
            n %= 100;
        }
        if (n >= 20) {
            ans += " " + m[n/10*10];
            n %= 10;
        }
        if (n == 0) {
            if (ans.size() == 0) {
                ans += " " + m[0];
            }
        } else {
            ans += " " + m[n];
        }

        return ans.substr(1);
    }

public:
    Solution() {
        m[0] = "Zero";
        m[1] = "One";
        m[2] = "Two";
        m[3] = "Three";
        m[4] = "Four";
        m[5] = "Five";
        m[6] = "Six";
        m[7] = "Seven";
        m[8] = "Eight";
        m[9] = "Nine";
        m[10] = "Ten";
        m[11] = "Eleven";
        m[12] = "Twelve";
        m[13] = "Thirteen";
        m[14] = "Fourteen";
        m[15] = "Fifteen";
        m[16] = "Sixteen";
        m[17] = "Seventeen";
        m[18] = "Eighteen";
        m[19] = "Nineteen";
        m[20] = "Twenty";
        m[30] = "Thirty";
        m[40] = "Forty";
        m[50] = "Fifty";
        m[60] = "Sixty";
        m[70] = "Seventy";
        m[80] = "Eighty";
        m[90] = "Ninety";
    }

    string numberToWords(int num) {
        int mul = 1000000000;
        vector<string> unit = {"Billion", "Million", "Thousand"};
        string ans;

        for (int i = 0; i < 3; ++i) {
            int tail = num / mul;
            if (tail != 0) {
                ans += " " + count(tail);
                ans += " " + unit[i];
            }
            num %= mul;
            mul /= 1000;
        }

        if (num == 0) {
            if (ans.size() == 0) {
                ans += " " + count(0);
            }
        } else {
            ans += " " + count(num);
        }

        return ans.substr(1);
    }
};
/*
 * very tedious
 */
class Solution {
private:
    string toWords(int num) {
        unordered_map<int, string> mapping;
        mapping[1] = "One";
        mapping[2] = "Two";
        mapping[3] = "Three";
        mapping[4] = "Four";
        mapping[5] = "Five";
        mapping[6] = "Six";
        mapping[7] = "Seven";
        mapping[8] = "Eight";
        mapping[9] = "Nine";
        mapping[10] = "Ten";
        mapping[11] = "Eleven";
        mapping[12] = "Twelve";
        mapping[13] = "Thirteen";
        mapping[14] = "Fourteen";
        mapping[15] = "Fifteen";
        mapping[16] = "Sixteen";
        mapping[17] = "Seventeen";
        mapping[18] = "Eighteen";
        mapping[19] = "Nineteen";
        mapping[20] = "Twenty";
        mapping[30] = "Thirty";
        mapping[40] = "Forty";
        mapping[50] = "Fifty";
        mapping[60] = "Sixty";
        mapping[70] = "Seventy";
        mapping[80] = "Eighty";
        mapping[90] = "Ninety";
        mapping[100] = "Hundred";

        string ans;
        if (num >= 100) {
            ans += " " + mapping[num/100] + " " + mapping[100];
            num %= 100;
        }
        if (num >= 20) {
            ans += " " + mapping[num/10*10];
            if (num % 10) ans += " " + mapping[num%10];
        } else if (num != 0) {
            ans += " " + mapping[num];
        }
        return ans.substr(1);
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string ans;
        if (num >= 1000000000) {
            ans += " " + toWords(num / 1000000000) + " Billion";
            num %= 1000000000;
        }
        if (num >= 1000000) {
            ans += " " + toWords(num / 1000000) + " Million";
            num %= 1000000;
        }
        if (num >= 1000) {
            ans += " " + toWords(num / 1000) + " Thousand";
            num %= 1000;
        }
        if (num != 0) {
            ans += " " + toWords(num);
        }
        return ans.substr(1);
    }
};
