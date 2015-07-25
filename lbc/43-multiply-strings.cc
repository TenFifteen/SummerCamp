/*
题目大意：
大整数乘法。非负。

解题思路：
按照每一位来进行一位乘法。
然后将结果加起来。

遇到的问题：
没有问题。代码细节。
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