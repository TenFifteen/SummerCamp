/*
题目大意：
有一个字符串。求出这个字符串中所有子串中，没有重复字母的子串的长度的最长值。

解题思路：
采用卡尺法，对于卡尺内的数据，保证都是没有重复字母的一个子串；如果当前考察的字母的数量不是0，
那么就把卡尺的左边前移，else就移动卡尺的右端。
时间复杂度：n，空间复杂度：1

遇到的问题：
中间对于buffer的使用，经常容易忘记使用s的字符，而容易用front或者end来索引，导致问题。这个问题的出现，
一方面是由于疏忽，一方面是因为int和char之间可以互相转换。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1)return s.size();
        int front = 1;
        int end = 0;
        int ans = 1;
        map<char,int> buffer;
        buffer[s[0]]++;
        while(front < s.size()){
            if(buffer[s[front]] != 0){
                buffer[s[end]]--;
                end++;
            }else{
                buffer[s[front]]++;
                front++;
                if(front - end > ans){
                    ans = front - end;
                }
            }
        }
        return ans;
    }
};