/*
题目大意：
给一个字符串，求出字符串中最后一个单词的长度。

解题思路：
直接遍历就行。记住最后一个单词的长度。

遇到的问题：
一次通过。

再次阅读：
虽然是一个简单题，但是感觉可以从后往前遍历啊。另外就是要跟面试官确认是否有trailing的space

*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0)return 0;
        int len = 0;
        bool last = true;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' '){
                last = true;
                continue;
            }
            if(last){
                last = false;
                len = 1;
            }else{
                len++;
            }
        }
        return len;
    }
};