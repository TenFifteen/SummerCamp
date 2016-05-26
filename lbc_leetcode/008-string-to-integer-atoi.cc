/*
题目大意：
实现atoi函数。需要自己考虑多种情况的存在。

解题思路：
首先需要考虑前导空格；然后需要考虑正负号；还要考虑溢出。
对于前导空格，直接去掉；
对于正负号，对第一个非空的字符进行考虑；
对于溢出，需要考虑新计算的value/10 == old这个条件。
在溢出时，需要考虑符号。
如果没有转换则默认为0.

遇到的问题：
对于溢出条件的判断，一开始采用的是new 《 old。结果发现这样是有问题的。

再次阅读：
这道题主要是考察string to integer的过程中需要注意的各种情况。
起始空格的处理，符号处理，溢出处理，空字符串处理等等。
DISCUSS中也不过是这么做的，只不过写的简便一些罢了。
*/
class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        int index = 0;
        while(index < str.size() && str[index] == ' '){
            index++;
        }
        if(index >= str.size())return 0;
        bool neg = false;
        if(str[index] == '-'){
            neg = true;
            index++;
        }else if(str[index] == '+'){
            index++;
        }
        while(index < str.size()){
            if(str[index] <= '9' && str[index] >= '0'){
                int new_value = ans * 10;
                new_value += str[index]-'0';
                if(new_value/10 != ans){
                    if(neg){
                        return INT_MIN;
                    }else{
                        return INT_MAX;
                    }
                }
                ans = new_value;
                index++;
            }else{
                if(neg){
                    return -ans;
                }else{
                    return ans;
                }
            }
        }
        if(neg){
            return -ans;
        }else{
            return ans;
        }
    }
};
/*
第二次做：
看了一下之前写的代码，竟然惊人的相似。。。难道一个人写的代码，真的很难改变么？？？
不过这个题目中的各种Corner case一定要好好的想想，面试中一定要搞清楚。
*/
class Solution {
private:
    bool isDigit(char ch) {
        return ch <= '9' && ch >= '0';
    }
public:
    int myAtoi(string str) {
        int index = 0;
        while (index < str.size() && str[index] == ' ') index++;
        if (index == str.size()) return 0;
        
        bool sign = false;
        if (str[index] == '+') {
            index++;
        } else if (str[index] == '-') {
            index++;
            sign = true;
        }
        
        int ans = 0;
        while (index < str.size() && isDigit(str[index])) {
            int new_ans = ans * 10;
            new_ans += str[index++] - '0';
            
            if (new_ans / 10 != ans) {
                if (sign) return INT_MIN;
                else return INT_MAX;
            }
            ans = new_ans;
        }
        
        if (sign) return -ans;
        else return ans;
    }
};