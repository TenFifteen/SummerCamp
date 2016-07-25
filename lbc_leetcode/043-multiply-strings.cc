/*
题目大意：
大整数乘法。非负。

解题思路：
按照每一位来进行一位乘法。
然后将结果加起来。

遇到的问题：
没有问题。代码细节。

再次阅读：
虽然感觉没有太大的思路问题，但是感觉效率稍微有点问题。
然后看到DISCUSS中有一个用迭代的方式计算的，而且空间是一次性申请。
感觉这个写法实在是无懈可击啊：
string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }

    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0")return num1;
        if(num2 == "0")return num2;
        string ans;
        for(int i = num2.size()-1; i >= 0; --i){
            if(num2[i] == '0')continue;
            string tmp = subMul(num1, num2[i]-'0');
            if(ans == ""){
                ans = tmp+string(num2.size()-i-1, '0');
            }else{
                ans = add(ans, tmp+string(num2.size()-i-1, '0'));
            }
        }
        return ans;
    }

    string subMul(string num, int x){
        int index = num.size()-1;
        int yu = 0;
        string ans;
        while(index >= 0 || yu){
            if(index >= 0){
                yu += (num[index]-'0')*x;
                index--;
            }
            ans.push_back(yu%10+'0');
            yu /= 10;
        }
        for(int i = 0; i < ans.size()/2; ++i){
            swap(ans[i], ans[ans.size()-1-i]);
        }
        return ans;
    }
    string add(string s1, string s2){
        int index1 = s1.size()-1;
        int index2 = s2.size()-1;
        int yu = 0;
        string ans;
        while(index1 >= 0 || index2 >= 0 || yu){
            if(index1 >= 0){
                yu += s1[index1]-'0';
                index1--;
            }
            if(index2 >= 0){
                yu += s2[index2]-'0';
                index2--;
            }
            ans.push_back(yu%10+'0');
            yu /= 10;
        }
        for(int i = 0; i < ans.size()/2; ++i){
            swap(ans[i], ans[ans.size()-1-i]);
        }
        return ans;
    }
};
/*
第二次做：
竟然写的跟第一次是基本一样的。。。
虽然没有DISCUSS中的简洁，不过也还是挺好的啦。
*/
class Solution {
    string addString(string num1, string num2) {
        string ans(max(num1.size(), num2.size())+1, '0');
        int i1 = num1.size()-1, i2 = num2.size()-1, ia = ans.size()-1;
        int carry = 0;

        while (i1 >= 0 || i2 >= 0) {
            if (i1 >= 0) carry += num1[i1--] - '0';
            if (i2 >= 0) carry += num2[i2--] - '0';
            ans[ia--] = '0' + carry % 10;
            carry /= 10;
        }
        if (carry) ans[ia--] = '0' + carry;

        return ans.substr(ia+1, ans.size());
    }

    string mulDigit(string num, int digit) {
        if (digit == 0) return "0";
        if (digit == 1) return num;

        string ans(num.size()+1, '0');
        int in = num.size()-1, ia = ans.size()-1, carry = 0;
        while (in >= 0) {
            carry += (num[in--]-'0') * digit;
            ans[ia--] = carry % 10 + '0';
            carry /= 10;
        }
        if (carry) ans[ia--] = '0' + carry;
        return ans.substr(ia+1, ans.size());
    }
public:
    string multiply(string num1, string num2) {
        assert(num1.size() && num2.size());
        if (num1 == "0" || num2 == "0") return "0";
        string ans = "0";

        for (int i = num1.size()-1; i >= 0; --i) {
            ans = addString(ans, mulDigit(num2, num1[i]-'0')+string(num1.size()-i-1, '0'));
        }

        return ans;
    }
};
/*
 *可以
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        string ans(num1.size()+num2.size(), '0');
        for (int i = num1.size()-1; i >= 0; --i) {
            int carry = 0;
            for (int j = num2.size()-1; j >= 0; --j) {
                carry += (num1[i]-'0') * (num2[j]-'0');
                int index = i+j+1;
                carry += ans[index] - '0';
                ans[index] = '0' + carry % 10;
                carry /= 10;
            }
            if (carry != 0) {
                ans[i] = carry + '0';
            }
        }

        int index = 0;
        while (ans[index] == '0') index++;
        return ans.substr(index);
    }
};
