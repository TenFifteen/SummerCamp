/*
题目：17 % 二进制表示 困难

题目大意：
给定一个字符串表示的浮点数，将其转化成二进制表示。

解题思路：
就是用string进行乘除操作

遇到的问题：
一开始不理解怎么用二进制表示。
看了网上别人的说法才知道，整数部分还是原来的mod2；
而小数部分则是不断的*2。
然后中间还有几个小bug，调了一会。
*/
class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        if (n == "") return n;
        int index = 0;
        while (index < n.size() && n[index] != '.') index++;
        string left = n.substr(0, index);
        string right = n.substr(index+1, n.size());
        right = rtrip(right);
        string ans;
        while (left != "") {
            if ((left[left.size()-1]-'0') % 2) {
                ans.push_back('1');
            } else {
                ans.push_back('0');
            }
            left = div2(left);
        }
        reverse(ans.begin(), ans.end());
        if (right == "") return ans;
        string tmp;
        while (tmp.size() <= 32) {
            string mul = mul2(right);
            if (mul.size() > right.size()) {
                tmp.push_back('1');
                mul = mul.substr(1, right.size());
            } else {
                tmp.push_back('0');
            }
            right = rtrip(mul);
            if (right == "") {
                return ans + '.' + tmp;
            }
        }
        return "ERROR";
    }
    
    string rtrip(string s) {
        int index = s.size()-1;
        while (index >= 0 && s[index] == '0') index--;
        if (index < 0) return "";
        if (index == s.size()-1) return s;
        return s.substr(0, index+1);
    }
    
    string mul2(string s) {
        string ret;
        int cur = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            cur += (s[i]-'0') * 2;
            ret.push_back(cur%10 + '0');
            cur /= 10;
        }
        if (cur) {
            ret.push_back(cur + '0');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    string div2(string s) {
        int cur = 0;
        string ret;
        for (int i = 0; i < s.size(); ++i) {
            cur *= 10;
            cur += s[i]-'0';
            ret.push_back(cur/2 + '0');
            cur %= 2;
        }
        if (ret[0] == '0') {
            return ret.substr(1, ret.size());
        } else {
            return ret;
        }
    }
};

