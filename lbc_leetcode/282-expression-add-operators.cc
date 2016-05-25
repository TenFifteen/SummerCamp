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
/*
第二次做：
这次虽然想到点上了，结果思路想反了，从后往前了，结果乘法处理不了。
然后又看了下之前的写法，才觉得这种思路好牛逼呀。尤其是那个last的使用。
*/
class Solution {
private:
    void dfs(vector<string> &ans , string num, string out, int target, long long cur, long long last) {
        if (num.size() == 0) {
            if (target == cur) {
                ans.push_back(out);
            }
            return;
        }
        
        for (int i = 0; i < num.size(); ++i) {
            string now = num.substr(0, i+1);
            string next = num.substr(i+1);
            long long n = stoll(now);
            
            if (num[0] == '0' && i > 0) break;
            
            if (out.size() == 0) {
                dfs(ans, next, now, target, n, n);
            } else {
                dfs(ans, next, out + '+' + now, target, cur+n, n);
                dfs(ans, next, out + '-' + now, target, cur-n, -n);
                dfs(ans, next, out + '*' + now, target, cur-last+last*n, last*n);
            }
        }
    }
    
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(ans, num, "", target, 0, 0);
        return ans;
    }
    
    vector<string> addOperatorsI(string num, int target) {
        vector<string> ans;
        
        if (num.size() == 0) return ans;
        //cout << num << " " << target << endl;
        
        for (int i = num.size()-1; i > 0; --i) {
            string right = num.substr(i);
            string left = num.substr(0, i);
            long long cur = stoll(right);
            
            vector<string> ret = addOperators(left, target - cur); // +
            for (auto r : ret) ans.push_back(r + "+" + right);
            
            ret = addOperators(left, target + cur); // -
            for (auto r : ret) ans.push_back(r + "-" + right);
            
            if (cur != 0 && target % cur) {
                ret = addOperators(left, target / cur); // *
                for (auto r : ret) ans.push_back(r + "*" + right);
            }
        }
        
        if (stoll(num) == target) ans.push_back(num);
        return ans;
    }
};