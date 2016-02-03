/*
题目大意：
给定一个字符串，其中只有小写字母。将其中所有的重复的字母都去掉，并且留下的字母按照原字符串顺序，并且是
所有的可能中字典序最小的。

解题思路：
用一个stack来存放当前位置找到的所有不重复的字母。然后从前往后考虑字符串中每个字母，如果字母已经在stack中了。那就不用管当前的字母。
如果字母没有在stack中，则需要加到stack中。但是需要把栈顶所有大于当前字母，并且后面还存在的字母都弹出栈。

遇到的问题：
虽然是一个中等难度的题目。感觉也不是很难，但是想了好久都没有想出来。实在是难受的不行啊。
而且看网上人家有好多种解法。

再次阅读：
感觉这道题目应该是用这种栈的方式来做就是最合适的了。
不过在DISCUSS中还找到了一个递归方式的解。其实我觉得这种方式也是可以用迭代式的来做的。
public class Solution {
    public String removeDuplicateLetters(String s) {
        int[] cnt = new int[26];
        int pos = 0; // the position for the smallest s[i]
        for (int i = 0; i < s.length(); i++) cnt[s.charAt(i) - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < s.charAt(pos)) pos = i;
            if (--cnt[s.charAt(i) - 'a'] == 0) break;
        }
        return s.length() == 0 ? "" : s.charAt(pos) + removeDuplicateLetters(s.substring(pos + 1).replaceAll("" + s.charAt(pos), ""));
    }
}
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<int> count(26, 0);
        vector<bool> inStack(26, false);
        
        for (auto ch : s) {
            count[ch-'a']++;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (!inStack[s[i]-'a']) {
                while (ans.size() > 0 && ans.back() > s[i] && count[ans.back()-'a'] > 0) {
                    inStack[ans.back()-'a'] = false;
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                inStack[s[i]-'a'] = true;
            }
            
            count[s[i]-'a']--;
        }
        
        return ans;
    }
};