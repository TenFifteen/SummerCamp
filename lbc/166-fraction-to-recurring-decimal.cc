/*
题目大意：
给一个分数，求其小数表示。并且处理循环的情况。

解题思路：
首先要注意符号，当然也就有了溢出的问题。
然后要注意numerator为0的时候，不可以在结果中带符号。
最后处理循环部分用map记录已经访问过的状态。包括当前的余数和当前的结果。

遇到的问题：
全都遇到了。包括符号，溢出，-0.
一开始还没有记录正确的状态，只记录了当前结果，没有记录当前的余数，所以出错了。
感觉这个题目的细节之处真是太多啊。
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)return "0";
        bool neg = false;
        long num, den;
        if(numerator < 0){
            neg = !neg;
            num = numerator;
            num = -num;
        }else{
            num = numerator;
        }
        if(denominator < 0){
            neg = !neg;
            den = denominator;
            den = -den;
        }else{
            den = denominator;
        }
        string ans;
        if(neg){
            ans += "-";
        }
        ans += to_string(num/den);
        if(num % den == 0){
            return ans;
        }
        ans.push_back('.');
        num %= den;
        map<pair<int,int>, int> hist; 
        while(num != 0){
            num *= 10;
            auto cur = make_pair(num/den, num%den);
            if(hist.count(cur)){
                return ans.substr(0, hist[cur]) + "(" + ans.substr(hist[cur], ans.size()-hist[cur]) + ")";
            }else{
                hist[cur] = ans.size();
            }
            ans.push_back(cur.first+'0');
            num = cur.second;
        }
        return ans;
    }
};