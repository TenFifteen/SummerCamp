/*
题目大意：
给定一个字符串和一个字典。求所有的用字典中的单词分割字符串的结果。

解题思路：
动态规划。反向追踪。

遇到的问题：
一开始竟然错了一个将赋值写成了==的形式。。。找了好久

再次阅读：
没想到之前想到的竟然是这么个思路。不过感觉还是挺好的。其实吧，我觉得，这种需要输出各种方案的
最终的结果的题目，复杂度本身都应该是很高了，所以递归的方式也没啥问题：
public List<String> wordBreak(String s, Set<String> dict) {
    List<String> result = new ArrayList<String>();
    for(int j = s.length() - 1; j >= 0; j--){
        if(dict.contains(s.substring(j)))
            break;
        else{
            if(j == 0)
                return result;
        }
    }
    for(int i = 0; i < s.length()-1; i++)
    {
        if(dict.contains(s.substring(0,i+1)))
        {
            List<String> strs = wordBreak(s.substring(i+1,s.length()),dict);
            if(strs.size() != 0)
                for(Iterator<String> it = strs.iterator();it.hasNext();)
                {
                    result.add(s.substring(0,i+1)+" "+it.next());
                }
        }
    }
    if(dict.contains(s)) result.add(s);
    return result;
}
*/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ans;
        if(s.size() == 0)return ans;
        vector<vector<bool>> buf(s.size(), vector<bool>(s.size(), false));
        for(int i = 0;i < s.size(); ++i){
            for(int j = i; j < s.size(); ++j){
                buf[i][j] = wordDict.count(s.substr(i, j-i+1)) > 0;
            }
        }
        
        vector<bool> dp(s.size(), false);
        dp[0] = buf[0][0];
        for(int i = 1; i < s.size(); ++i){
            if(buf[0][i]){
                dp[i] = true;
                continue;
            }
            for(int j = 0; j < i; ++j){
                if(dp[j] && buf[j+1][i]){
                    dp[i] = true;
                    break;
                }
            }
        }
        vector<string> cur;
        sub(ans, dp, buf, s, s.size()-1, cur);
        return ans;
    }
    
    void sub(vector<string> &ans, vector<bool> &dp, vector<vector<bool>> &buf, string &s, int index, vector<string> &cur){
        if(index < 0){
            string tmp = cur[cur.size()-1];
            if(cur.size() > 1)for(int i = cur.size()-2; i >= 0; --i){
                tmp += " " + cur[i];
            }
            ans.push_back(tmp);
            return;
        }
        
        if(dp[index] && buf[0][index]){
            cur.push_back(s.substr(0, index+1));
            sub(ans, dp, buf, s, -1, cur);
            cur.pop_back();
        }
        
        for(int i = 0; i < index; ++i){
            if(dp[i] && buf[i+1][index]){
                cur.push_back(s.substr(i+1, index-i));
                sub(ans, dp, buf, s, i, cur);
                cur.pop_back();
            }
        }
    }
};