/*
题目大意：
判断一个字符串是否是合法的数字表示。

解题思路：
合法的数字表示符合该正则表达式："[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)?"
用自动机表示该正则表达式即可。

遇到的问题：
有哪些合法的数字，傻傻分不清。终于最后看到了这个正则表达式，才知道啥叫有效的数字。
哎，这个题实在是麻烦啊。

再次阅读：
其实就是一个正则表达式。
下面这个是DISCUSS中直接用正则表达式求解的方法：
public class Solution {
public boolean isNumber(String s) {
    s = s.trim();
    if (s.length() == 0)
        return false;
    if (s.matches("[+-]?(([0-9]*\\.?[0-9]+)|([0-9]+\\.?[0-9]*))([eE][+-]?[0-9]+)?"))
        return true;
    else
        return false;

}
另外，下面这个写法也是挺简单的，值得借鉴一下：
bool isNumber(const char *s)
{
    int i = 0;

    // skip the whilespaces
    for(; s[i] == ' '; i++) {}

    // check the significand
    if(s[i] == '+' || s[i] == '-') i++; // skip the sign if exist

    int n_nm, n_pt;
    for(n_nm=0, n_pt=0; (s[i]<='9' && s[i]>='0') || s[i]=='.'; i++)
        s[i] == '.' ? n_pt++:n_nm++;
    if(n_pt>1 || n_nm<1) // no more than one point, at least one digit
        return false;

    // check the exponent if exist
    if(s[i] == 'e') {
        i++;
        if(s[i] == '+' || s[i] == '-') i++; // skip the sign

        int n_nm = 0;
        for(; s[i]>='0' && s[i]<='9'; i++, n_nm++) {}
        if(n_nm<1)
            return false;
    }

    // skip the trailing whitespaces
    for(; s[i] == ' '; i++) {}

    return s[i]==0;  // must reach the ending 0 of the string
}
*/
class Solution {
public:
    bool isNumber(string s) {
        string reg = "[-+]?(\\d+\\.?|\\.\\d+)\\d*(e[-+]?\\d+)?";
        int start = 0, end = s.size()-1;
        while(start < s.size() && s[start] == ' ')start++;
        while(end >= 0 && s[end] == ' ')end--;
        s = s.substr(start, end-start+1);
        if(s == "")return false;
        int state = 0;
        for(int i = 0; i < s.size(); ++i){
            switch(state){
                case 0://start state
                    if(s[i] == '+' || s[i] == '-'){
                        state = 1;
                    }else if(s[i] == '.'){
                        state = 2;
                    }else if(s[i] >= '0' && s[i] <= '9'){
                        state = 3;
                    }else{
                        return false;
                    }
                    break;
                case 1://accept no sign number
                    if(s[i] == '.'){
                        state = 2;
                    }else if(s[i] >= '0' && s[i] <= '9'){
                        state = 3;
                    }else{
                        return false;
                    }
                    break;
                case 2://only accept digits
                    if(s[i] < '0' || s[i] > '9'){
                        return false;
                    }else{
                        state = 4;
                    }
                    break;
                case 3://accept digits+.+digits
                    if(s[i] == 'e'){
                        state = 5;
                    }else if(s[i] >= '0' && s[i] <= '9'){
                        continue;
                    }else if(s[i] == '.'){
                        state = 4;
                    }else{
                        return false;
                    }
                    break;
                case 4://has digit, only accept digits
                    if(s[i] >= '0' && s[i] <= '9'){
                        continue;
                    }else if(s[i] == 'e'){
                        state = 5;
                    }else{
                        return false;
                    }
                    break;
                case 5:
                    if(s[i] == '-' || s[i] == '+'){
                        state = 6;
                    }else if(s[i] <= '9' && s[i] >= '0'){
                        state = 7;
                    }else{
                        return false;
                    }
                    break;
                case 6:
                    if(s[i] < '0' || s[i] > '9'){
                        return false;
                    }else{
                        state = 7;
                    }
                    break;
                case 7:
                    if(s[i] < '0' || s[i] > '9'){
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        if(state == 3 || state == 4 || state == 7)return true;
        return false;
    }
};
/*
第二次做：
这次虽然自己想到了这个规则了。但是还是写的不是很顺利。
最后参考了一下别人的，不过感觉以后可以就这么写了。
*/
class Solution {
    string trim(string s) {
        if (s == "") return "";
        int start = 0;
        while (start < s.size() && s[start] == ' ') start++;
        int end = s.size()-1;
        while (end > start && s[end] == ' ') end--;
        if (start >= s.size()) return "";
        return s.substr(start, end-start+1);
    }

    bool isSign(char ch) {
        return ch == '+' || ch == '-';
    }

    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    bool isExp(char ch) {
        return ch == 'e' || ch == 'E';
    }

    bool isDot(char ch) {
        return ch == '.';
    }



public:
    bool isNumber(string s) {
        s = trim(s);
        if (s == "") return false;
        int index = 0;

        if (isSign(s[index])) index++;

        int num = 0, dot = 0;
        while (index < s.size() && (isDigit(s[index]) || isDot(s[index]))) {
            if (isDot(s[index])) dot++;
            else num ++;
            index++;
        }
        if (num == 0 || dot > 1) return false;

        if (index < s.size() && isExp(s[index])) {
            index++;
            if (index == s.size()) return false;
            if (isSign(s[index])) index++;
            int num = 0;
            while (index < s.size() && isDigit(s[index])) {
                index++;
                num++;
            }
            if (num == 0) return false;
        }

        return index == s.size();
    }
};
/*
 * thank god, a surprise, I remenber it...
 */
class Solution {
private:
    string trim(string s) {
        if (s == "") return s;
        int left = 0, right = s.size()-1;
        while (left < s.size() && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;
        if (right < left) return "";
        return s.substr(left, right-left+1);
    }

public:
    bool isNumber(string s) {
        s = trim(s);

        int index = 0;
        while (index < s.size() && s[index] == ' ') index++;
        if (index == s.size()) return false;

        if (s[index] == '+' || s[index] == '-') index++;
        if (index == s.size()) return false;

        int dot = 0, num = 0;
        while (index < s.size() && ((s[index] <= '9' && s[index] >= '0') || s[index] == '.')) {
            if (s[index] == '.') dot++;
            else num++;
            index++;
        }
        if (dot > 1 || num == 0) return false;
        if (index == s.size()) return true;

        if (s[index] == 'e' || s[index] == 'E') {
            index++;
            if (index == s.size()) return false;
            if (s[index] == '+' || s[index] == '-') index++;
            if (index == s.size()) return false;
            while (index < s.size() && s[index] >= '0' && s[index] <= '9') index++;
        }

        return index == s.size();
    }
};
