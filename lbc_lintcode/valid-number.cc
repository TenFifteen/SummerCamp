/*
题目：27 % 有效数字 困难

题目大意：
给定一个字符串，问是否是合法的数字表示

解题思路：
正则表达式转化为转台之间的转化

遇到的问题：
直接把leetcode的代码拿过来了。
*/
class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // Write your code here
        string reg = "[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)?";
        int start = 0, end = s.size()-1;
        while(start < s.size() && s[start] == ' ')start++;
        while(end >= 0 && s[end] == ' ')end--;
        s = s.substr(start, end-start+1);
        if(s == "")return false;
        int state = 0;
        for(int i = 0; i < s.size(); ++i){
            switch(state){
                case 0://start state
                    if(s[i] == '+' || s[i] == '-'){
                        state = 1;
                    }else if(s[i] == '.'){
                        state = 2;
                    }else if(s[i] >= '0' && s[i] <= '9'){
                        state = 3;
                    }else{
                        return false;
                    }
                    break;
                case 1://accept no sign number
                    if(s[i] == '.'){
                        state = 2;
                    }else if(s[i] >= '0' && s[i] <= '9'){
                        state = 3;
                    }else{
                        return false;
                    }
                    break;
                case 2://only accept digits
                    if(s[i] < '0' || s[i] > '9'){
                        return false;
                    }else{
                        state = 4;
                    }
                    break;
                case 3://accept digits+.+digits
                    if(s[i] == 'e'){
                        state = 5;
                    }else if(s[i] >= '0' && s[i] <= '9'){
                        continue;
                    }else if(s[i] == '.'){
                        state = 4;
                    }else{
                        return false;
                    }
                    break;
                case 4://has digit, only accept digits
                    if(s[i] >= '0' && s[i] <= '9'){
                        continue;
                    }else if(s[i] == 'e'){
                        state = 5;
                    }else{
                        return false;
                    }
                    break;
                case 5:
                    if(s[i] == '-' || s[i] == '+'){
                        state = 6;
                    }else if(s[i] <= '9' && s[i] >= '0'){
                        state = 7;
                    }else{
                        return false;
                    }
                    break;
                case 6:
                    if(s[i] < '0' || s[i] > '9'){
                        return false;
                    }else{
                        state = 7;
                    }
                    break;
                case 7:
                    if(s[i] < '0' || s[i] > '9'){
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        if(state == 3 || state == 4 || state == 7)return true;
        return false;
    }
};
