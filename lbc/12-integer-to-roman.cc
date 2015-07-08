/*
题目大意：
给定一个整数，然后将其转化为罗马数字表示。

解题思路：
罗马数字是由1、5、10、50、100、500、1000这些字符组成的。然后表示规则就是：
对于1-3：用三个连着的1
对于4：用5-1
对于5：5
对于5-8：用5+。。。
对于9：用10-1
然后从前往后的处理每个数字就可以了。

遇到的问题：
本来这个题目原来是不会的。结果今天查了一下百度。感觉应该就是这样贪心下来的。就试了一下，结果
竟然对了。

*/
class Solution {
public:
    string intToRoman(int num) {
        map<int,char> table;
        table[1] = 'I';
        table[5] = 'V';
        table[10] = 'X';
        table[50] = 'L';
        table[100] = 'C';
        table[500] = 'D';
        table[1000] = 'M';
        string ans;
        int len = 0;
        int tmp = num;
        while(tmp){
            len++;
            tmp /= 10;
        }
        tmp = 1;
        for(int i = 1; i < len; ++i){
            tmp *= 10;
        }
        for(int i = 0; i < len; ++i){
            int cur = num / tmp;
            if(cur == 9){
                ans.push_back(table[tmp]);
                ans.push_back(table[tmp*10]);
            }else if(cur >= 5){
                ans.push_back(table[tmp*5]);
                for(int j = 0; j < cur-5; ++j){
                    ans.push_back(table[tmp]);
                }
            }else if(cur == 4){
                ans.push_back(table[tmp]);
                ans.push_back(table[tmp*5]);
            }else{
                for(int j = 0; j < cur; j++){
                    ans.push_back(table[tmp]);
                }
            }
            num %= tmp;
            tmp /= 10;
        }
        return ans;
    }
};