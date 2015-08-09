/*
题目大意：
简单的计算算数表达式。

解题思路：
先除去字符串中的空格。
然后遍历一遍，将乘除先计算了。
然后再计算一遍加减。

遇到的问题：
竟然忘记了while循环中更新start了。真是罪过
*/
class Solution {
public:
    int calculate(string s) {
        string tmp;
        for(auto ch:s){
            if(ch == ' ')continue;
            tmp.push_back(ch);
        }
        s = tmp;
        vector<int> nums;
        vector<char> ops;
        int start = 0;
        while(start < s.size() && isDigit(s[start]))start++;
        nums.push_back(stoi(s.substr(0, start)));
        while(start < s.size()){
            ops.push_back(s[start]);
            start++;
            int end = start+1;
            while(end < s.size() && isDigit(s[end]))end++;
            if(ops[ops.size()-1] == '/'){
                ops.pop_back();
                nums[nums.size()-1] = nums[nums.size()-1] / stoi(s.substr(start, end-start));
            }else if(ops[ops.size()-1] == '*'){
                ops.pop_back();
                nums[nums.size()-1] = nums[nums.size()-1] * stoi(s.substr(start, end-start));
            }else{
                nums.push_back(stoi(s.substr(start, end-start)));
            }
            start = end;
        }
        for(int i = 0; i < ops.size(); ++i){
            if(ops[i] == '-'){
                nums[0] -= nums[i+1];
            }else{
                nums[0] += nums[i+1];
            }
        }
        return nums[0];
    }
    
    bool isDigit(char ch){
        return ch <= '9' && ch >= '0';
    }
};