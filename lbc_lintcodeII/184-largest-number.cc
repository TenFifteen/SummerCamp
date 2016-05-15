/*
题目大意：
给定一组数字，问怎么排列起来，它们拼接出来的字符串最大？

解题思路：
排序。见代码。

遇到的问题：
各种Corner case都想不到了。。。
*/
class Solution {
    struct Cmp {
        bool operator() (int a, int b) {
            string a_str = to_string(a);
            string b_str = to_string(b);
            
            return a_str+b_str > b_str+a_str;
        }
    };
    
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        sort(num.begin(), num.end(), Cmp());
        
        string ans;
        for (int i = 0; i < num.size(); ++i) {
            ans += to_string(num[i]);
        }
        
        // trim heading zeros
        int index = 0;
        while (index < ans.size() && ans[index] == '0') index++;
        
        if (index == ans.size()) return "0";
        else return ans.substr(index);
    }
};
