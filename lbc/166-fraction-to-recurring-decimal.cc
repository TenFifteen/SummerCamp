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

再次阅读：
感觉这道题的思路没啥问题了，就是代码稍微啰嗦一点。
如果真要参考的话，也可以参考一下这种只记录当前的余数的代码，感觉比我这种简洁一些：
string fractionToDecimal(int64_t n, int64_t d) {
    // zero numerator
    if (n == 0) return "0";

    string res;
    // determine the sign
    if (n < 0 ^ d < 0) res += '-';

    // remove sign of operands
    n = abs(n), d = abs(d);

    // append integral part
    res += to_string(n / d);

    // in case no fractional part
    if (n % d == 0) return res;

    res += '.';

    unordered_map<int, int> map;

    // simulate the division process
    for (int64_t r = n % d; r; r %= d) {

        // meet a known remainder
        // so we reach the end of the repeating part
        if (map.count(r) > 0) {
            res.insert(map[r], 1, '(');
            res += ')';
            break;
        }

        // the remainder is first seen
        // remember the current position for it
        map[r] = res.size();

        r *= 10;

        // append the quotient digit
        res += to_string(r / d);
    }

    return res;
}
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
/*
第二次做：
这次虽然状态记录对了，但是好多细节都没有考虑到。
首先是，正负问题；一般伴随着正负就有溢出的问题。
另外就是没有小数部分的问题，
然后是”-0“的问题。
这道题的关键就是这些小问题，所以一定要想清楚各种情况，才能开始动手写代码。
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool neg = false;
        long long num = numerator, den = denominator;
        if (num < 0) {
            neg = !neg;
            num = -num;
        }
        if (den < 0) {
            neg = !neg;
            den = -den;
        }
        
        long long integer = num / den;
        num %= den;
        
        string frac;
        unordered_map<long long, int> hash;
        while (num) {
            num *= 10;
            int digit = num / den;
            num %= den;
            
            long long key = (num << 4) + digit;
            
            if (hash.find(key) != hash.end()) {
                string ans = to_string(integer) + "." + frac.substr(0, hash[key]) + "(" + frac.substr(hash[key]) + ")";
                if (neg) {
                    return "-" + ans;
                } else {
                    return ans;
                }
            }
            hash[key] = frac.size();
            frac.push_back(digit + '0');
        }
        
        if (frac.size() == 0 && integer == 0) return "0";
        string ans = neg ? "-" + to_string(integer) : to_string(integer);
        if (frac.size() > 0) ans += "." + frac;
        return ans;
    }
};