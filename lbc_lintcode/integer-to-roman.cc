/*
题目：40 % 整数转罗马数字 中等

题目大意：
给定一个整数，将其转化为罗马数字

解题思路：
贪心，见leetcode说明

遇到的问题：
这个题目看了一下之前leetcode上的解法，直接把代码拿过来了。
*/
class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
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
        int tmp = n;
        while(tmp){
            len++;
            tmp /= 10;
        }
        tmp = 1;
        for(int i = 1; i < len; ++i){
            tmp *= 10;
        }
        for(int i = 0; i < len; ++i){
            int cur = n / tmp;
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
            n %= tmp;
            tmp /= 10;
        }
        return ans;
    }
};
