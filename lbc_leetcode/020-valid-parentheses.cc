/*
题目大意：
给一个由大中小括号组成的字符串，判断括号使用的是否有问题。

解题思路：
使用一个栈即可解决。如果是括号的左边，则入栈；如果是右边，如果当前队列不为空，
并且栈顶元素等于当前元素的对应的括号，则匹配成功，出栈；否则就是错的。
最后如果栈内还有元素，也是有问题的。

遇到的问题：
没啥问题，我挺喜欢这种问题的。

再次阅读：
比较经典的用stack解决的问题。
*/
class Solution {
public:
    bool isValid(string s) {
        map<char,char> buf;
        buf[')'] = '(';
        buf['}'] = '{';
        buf[']'] = '[';
        stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.size() == 0 || st.top() != buf[s[i]]){
                    return false;
                }
                st.pop();
            }
        }
        if(st.size() == 0){
            return true;
        }
        return false;
    }
};
/*
第二次做：
感觉这次已经很熟练了。虽然懒得没有用map，不过也还好啦。
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            } else {
                if (stk.empty()) return false;
                switch (ch) {
                    case ']':
                        if (stk.top() != '[') return false;
                        break;
                    case ')':
                        if (stk.top() != '(') return false;
                        break;
                    case '}':
                        if (stk.top() != '{') return false;
                        break;
                }
                stk.pop();
            }
        }
        
        return stk.empty();
    }
};