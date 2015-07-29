/*
题目大意：
数数，例如112就是2个1and1个2也就是2112。从1开始，数n次。

解题思路：
直接模拟进行数就是了。

遇到的问题：
一次通过。
*/
class Solution {
public:
    string countAndSay(int n) {
        string ans;
        if(n <= 0)return ans;
        ans = "1";
        for(int i = 1; i < n; ++i){
            string next;
            int index = 1,len = 1;
            while(true){
                while(index < ans.size() && ans[index] == ans[index-1]){
                    index++;
                    len++;
                }
                next += to_string(len);
                next += ans[index-1];
                if(index >= ans.size())break;
                index++;
                len = 1;
            }
            ans = next;
        }
        return ans;
    }
};