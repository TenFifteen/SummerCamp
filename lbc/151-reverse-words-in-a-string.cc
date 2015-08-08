/*
题目大意：
给定一个字符串，将其中所有的word都翻转。

解题思路：
注意题目中单词的定义：以空格为分割的字符序列。
而且，题目要求，如果首尾有空格，则省去；而且单词间多余一个空格都变为一个空格。

遇到的问题：
感觉这个跟翻转url的题目是很类似的。结果忘了处理多余空格的问题了。
然后又加上了处理空格的代码才过的。
不过感觉代码还需要整理一下，或者优化一下。
*/
class Solution {
public:
    void reverseWords(string &s) {
        if(s.size() == 0)return;
        string tmp;
        int cur = 0;
        while(cur < s.size()){
            while(cur < s.size() && s[cur] == ' ')cur++;
            if(cur >= s.size())break;
            tmp.push_back(' ');
            while(cur < s.size() && s[cur] != ' '){
                tmp.push_back(s[cur]);
                cur++;
            }
        }
        if(tmp == ""){
            s = tmp;
        }else if(tmp[0] == ' '){
            s = tmp.substr(1, tmp.size()-1);
        }else{
            s = tmp;
        }
        
        sub(s, 0, s.size()-1);
        int left = 0;
        while(left < s.size() && s[left] == ' ')left++;
        while(left < s.size()){
            int right = left+1;
            while(right < s.size() && s[right] != ' ')right++;
            sub(s, left, right-1);
            left = right+1;
            while(left < s.size() && s[left] == ' ')left++;
        }
    }
    
    void sub(string &s, int left, int right){
        for(int i = left; i < left+(right-left+1)/2; ++i){
            swap(s[i], s[right-i+left]);
        }
    }
};