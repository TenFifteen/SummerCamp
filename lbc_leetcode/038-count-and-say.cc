/*
题目大意：
数数，例如112就是2个1and1个2也就是2112。从1开始，数n次。

解题思路：
直接模拟进行数就是了。

遇到的问题：
一次通过。

再次阅读：
好像也就是这么做就可以了。就是直接进行模拟。
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
/*
第二次做：
简单题，但是感觉已经做得不是很顺利了。应该是今天做的已经够多了吧。
*/
class Solution {
public:
    string countAndSay(int n) {
        string ans;
        if (n < 1) return ans;
        
        ans = "1";
        for (int i = 1;i < n; ++i) {
            string next;
            int index = 0;
            while (index < ans.size()) {
                int last = index;
                while (index < ans.size() && ans[index] == ans[last]) index++;
                next += to_string(index-last);
                next.push_back(ans[last]);
            }
            ans = next;
        }
        
        return ans;
    }
};