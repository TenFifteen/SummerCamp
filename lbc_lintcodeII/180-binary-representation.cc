/*
题目大意：
给定一个字符串表示的浮点数，将其转化为2进制表示。

解题思路：
直接模拟

遇到的问题：
就是感觉长时间不写这种代码，已经生疏了。
两个函数都有致命的问题。还是慢慢找才找出来的。。
*/
class Solution {
    string divideBy2(const string &input) {
        string ans;
        int carry = 0;
        for (int i = 0; i < input.size(); ++i) {
            carry *= 10;
            carry += input[i]-'0';
            ans.push_back(carry / 2 + '0');
            carry %= 2;
        }
        
        int index = 0;
        while (index < ans.size() && ans[index] == '0') index++;
        if (index == ans.size()) return "";
        return ans.substr(index);
    }
    
    string multiplyBy2(const string &input) {
        string ans;
        int carry = 0;
        for (int i = input.size()-1; i >= 0; --i) {
            carry += (input[i]-'0')*2;
            ans.push_back(carry % 10 + '0');
            carry /= 10;
        }
        
        if (carry) {
            ans.push_back(carry + '0');
        }
        
        for (int i = 0; i < ans.size()/2; ++i) {
            swap(ans[i], ans[ans.size()-1-i]);
        }
        
        return ans;
    }
    
    string getBinaryFromInteger(string input) {
        string ans;
        while (input.size() > 0) {
            if ((input.back()-'0') % 2) ans.push_back('1');
            else ans.push_back('0');
            input = divideBy2(input);
        }
        
        for (int i = 0; i < ans.size()/2; ++i) {
            swap(ans[i], ans[ans.size()-1-i]);
        }
        return ans;
    }
    
    string trailingBlanks(const string &input) {
        int index = input.size()-1;
        while (index >= 0 && input[index] == '0') index--;
        if (index < 0) return "";
        return input.substr(0, index+1);
    }
    
    string getBinaryFromFraction(string input) {
        string ans;
        while (input.size() > 0) {
            string next = multiplyBy2(input);
            if (next.size() > input.size()) {
                ans.push_back('1');
                input = trailingBlanks(next.substr(1));
            }
            else {
                ans.push_back('0');
                input = trailingBlanks(next);
            }
            
            if (ans.size() > 32) return "";
        }
        return ans;
    }
    
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
        
        //cout << n.substr(0, index) << endl;
        //cout << n.substr(index+1) << endl;
        
        string ans = getBinaryFromInteger(n.substr(0, index));
        if (index+1 < n.size()) {
            string right = n.substr(index+1); // deal with 1.0
            if (right == string(right.size(), '0')) return ans;
            
            ans += ".";
            string fraction = getBinaryFromFraction(right);
            if (fraction == "") return "ERROR";
            ans += fraction;
        }
        
        return ans;
    }
};

