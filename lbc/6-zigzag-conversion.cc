/*
题目大意：
给定一个字符串，给定一个行数。将字符串转化为倒着的Z的形状，然后按照Z的一行一行的顺序输出最后的字符串。

解题思路：
直接模拟。按照写Z的过程，将每个字符串分到每一行中去。
时间复杂度：n。空间复杂度：n

遇到的问题：
这个题目比较简单。
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2)return s;
        vector<string> buf(numRows);
        int direction = 1;
        int i = 0;
        int index = 0;
        while(i < s.size()){
            buf[index].push_back(s[i]);
            i++;
            if(direction == 1){
                index++;
                if(index >= numRows){
                    direction = 0;
                    index = numRows-2;
                }
            }
            else{
                index--;
                if(index < 0){
                    direction = 1;
                    index = 1;
                }
            }
        }
        string ans;
        for(auto s: buf){
            ans += s;
        }
        return ans;
    }
};