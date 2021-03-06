/*
题目大意：
给一个数字，输出所有可能的括号的组合。

解题思路：
就是一个回溯问题。如果当前还剩下的右括号为0，则可以输出；如果左右括号数一样，
那么只能输出左括号；另外就是左右都可以输出的。

遇到的问题：
不要忘记输出之后要返回。

再次阅读：
之前的解法已经足够好了。
不过下面这种写法还是可以参考参考的。
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
};
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        sub(n, n, ans, cur);
        return ans;
    }

    void sub(int left, int right, vector<string> &ans, string &cur){
        if(right == 0){
            ans.push_back(cur);
            return;
        }
        if(left == right){
            cur.push_back('(');
            sub(left-1, right, ans, cur);
            cur.pop_back();
        }else{
            if(left > 0){
                cur.push_back('(');
                sub(left-1, right, ans, cur);
                cur.pop_back();
            }
            cur.push_back(')');
            sub(left, right-1, ans, cur);
            cur.pop_back();
        }
    }
};
/*
第二次做：
这次做的很顺利。
*/
class Solution {
    void dfs(vector<string> &ans, string now, int left, int right) {
        if (right == 0) {
            ans.push_back(now);
            return;
        }

        if (left != 0) dfs(ans, now+"(", left-1, right);
        if (left != right) dfs(ans, now+")", left, right-1);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, "", n, n);
        return ans;
    }
};
/*
 * 我竟然没有想出来该怎么搞。。还是参考了一下原来的代码。。。
 */
class Solution {
private:
    void sub(int left, int right, string now, vector<string> &ans) {
        if (right == 0) {
            ans.push_back(now);
            return;
        }
        if (left == right) {
            sub(left-1, right, now + "(", ans);
        } else if (left == 0) {
            sub(left, right-1, now + ")", ans);
        } else {
            sub(left-1, right, now + "(", ans);
            sub(left, right-1, now + ")", ans);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        sub(n, n, "", ans);
        return ans;
    }
};
