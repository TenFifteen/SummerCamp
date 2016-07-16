/*
题目大意：
给一个罗马数字，将其转换为阿拉伯数字。

解题思路：
与12题是反着的。也是利用贪心，从前往后找就行。

遇到的问题：
但是这个题目的代码如何才能写得好看点呢，感觉丑死了。
之前这个题目是不敢做的，但是感觉在变成了任务之后，好像是也没有多难。

再次阅读：
这个题目也是印象比较深刻的，因为当时很难理解别人是怎么做的。
不过现在看看以前的代码，实在是有些麻烦了。现在贴一个比较简洁的代码：
int romanToInt(string s)
{
    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };

   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i)
   {
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }

   return sum;
}
*/
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> table;
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
        int cur = 0;
        int ans = 0;
        while(cur < s.size()){
            int local = 0;
            switch(s[cur]){
                case 'I':
                    local = 1;
                    for(cur++; cur < s.size(); ++cur){
                        if(s[cur] == 'V'){
                            local = 4;
                            cur++;
                            break;
                        }else if(s[cur] == 'X'){
                            local = 9;
                            cur++;
                            break;
                        }else if(s[cur] == 'I'){
                            local += 1;
                        }else{
                            break;
                        }
                    }
                    break;
                case 'V':
                    local = 5;
                    for(cur++; cur < s.size(); ++cur){
                        if(s[cur] == 'I'){
                            local += 1;
                        }else{
                            break;
                        }
                    }
                    break;
                case 'X':
                    local = 10;
                    for(cur++; cur < s.size(); ++cur){
                        if(s[cur] == 'L'){
                            local = 40;
                            cur++;
                            break;
                        }else if(s[cur] == 'C'){
                            local = 90;
                            cur++;
                            break;
                        }else if(s[cur] == 'X'){
                            local += 10;
                        }else{
                            break;
                        }
                    }
                    break;
                case 'L':
                    local = 50;
                    for(cur++; cur < s.size(); ++cur){
                        if(s[cur] == 'X'){
                            local += 10;
                        }else{
                            break;
                        }
                    }
                    break;
                case 'C':
                    local = 100;
                    for(cur++; cur < s.size(); ++cur){
                        if(s[cur] == 'D'){
                            local = 400;
                            cur++;
                            break;
                        }else if(s[cur] == 'M'){
                            local = 900;
                            cur++;
                            break;
                        }else if(s[cur] == 'C'){
                            local += 100;
                        }else{
                            break;
                        }
                    }
                    break;
                case 'D':
                    local = 500;
                    for(cur++; cur < s.size(); ++cur){
                        if(s[cur] == 'C'){
                            local += 100;
                        }else{
                            break;
                        }
                    }
                    break;
                case 'M':
                    local = 1000;
                    for(cur += 1; cur < s.size(); ++cur){
                        if(s[cur] == 'M'){
                            local += 1000;
                        }else{
                            break;
                        }
                    }
                    break;
                default:
                    break;
            }
            ans += local;
        }
        return ans;
    }
};
/*
第二次做：
是的，我觉得这次我已经会做这道题了。
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mapping;
        mapping['I'] = 1;
        mapping['V'] = 5;
        mapping['X'] = 10;
        mapping['L'] = 50;
        mapping['C'] = 100;
        mapping['D'] = 500;
        mapping['M'] = 1000;

        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i+1 < s.size() && mapping[s[i]] < mapping[s[i+1]]) {
                ans -= mapping[s[i]];
            } else {
                ans += mapping[s[i]];
            }
        }
        return ans;
    }
};
/*
 * 都记住了。。
 */
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> um;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;

        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i+1 != s.size() && um[s[i]] < um[s[i+1]]) ans -= um[s[i]];
            else ans += um[s[i]];
        }
        return ans;
    }
};
