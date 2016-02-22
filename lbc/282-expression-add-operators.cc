/*
题目大意：
给定一串数字，可以在其中任意位置加上+、-、*三种符号，（都是二元运算符号），使得最后的计算结果为target

解题思路：
一开始感觉这个题目实在是太复杂了，因为很有可能会溢出啥的。
但是看了网上一个人的解法之后，感觉最大好像也没有超过long long所以就按照人家的思路来做了。
其实就是一个简单的DFS，但是自己一开始没敢用。

遇到的问题：
首先就是自己不敢想。另外可能就是题目的确是没说明白，要是说明白了，直接就是不会超过long long的数字的长度的话，
我觉得我应该还是可以考虑做一下的。
但是可能代码写不到这么简洁。
另外的收获就是string的一堆转换函数（stoi, stol, stoul, stoll, stoull, stof, stod, stold)

再次阅读：
看来这种思路已经是最好的思路了啊。原来还想过动归的解法。现在想来这种需要保存大量的结果，或者说搜索的复杂度跟结果复杂度相等
的情况，应该是不需要动归的，动归可能会浪费更多的空间。
*/
class Solution {
private:
    void dfs(vector<string> &ans, string num, string out, int target, long long cur, long long last) {
        if (target == cur && num.size() == 0) {
            ans.push_back(out);
            return;
        }
        
        for (int i = 0; i < num.size(); ++i) {
            string now = num.substr(0, i+1);
            string next = num.substr(i+1);
            
            if (now[0] == '0' && i > 0) break;
            
            if (out.size() > 0) {
                dfs(ans, next, out + "+" + now, target, cur + stoll(now), stoll(now));
                dfs(ans, next, out + "-" + now, target, cur - stoll(now), -stoll(now));
                dfs(ans, next, out + "*" + now, target, cur-last+last*stoll(now), last*stoll(now));
            } else {
                dfs(ans, next, now, target, stoll(now), stoll(now));
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(ans, num, "", target, 0, 0);
        return ans;
    }
};