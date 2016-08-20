/*
题目大意：
简单的计算算数表达式。

解题思路：
先除去字符串中的空格。
然后遍历一遍，将乘除先计算了。
然后再计算一遍加减。

遇到的问题：
竟然忘记了while循环中更新start了。真是罪过

再次阅读：
一直觉得自己做的不够简洁。这下好了，在DISCUSS中找到了一个简洁到令人发指的地步的代码：
int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' or op == '-') {
            total += term;
            in >> term;
            term *= 44 - op;
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}
*/
class Solution {
public:
    int calculate(string s) {
        string tmp;
        for(auto ch:s){
            if(ch == ' ')continue;
            tmp.push_back(ch);
        }
        s = tmp;
        vector<int> nums;
        vector<char> ops;
        int start = 0;
        while(start < s.size() && isDigit(s[start]))start++;
        nums.push_back(stoi(s.substr(0, start)));
        while(start < s.size()){
            ops.push_back(s[start]);
            start++;
            int end = start+1;
            while(end < s.size() && isDigit(s[end]))end++;
            if(ops[ops.size()-1] == '/'){
                ops.pop_back();
                nums[nums.size()-1] = nums[nums.size()-1] / stoi(s.substr(start, end-start));
            }else if(ops[ops.size()-1] == '*'){
                ops.pop_back();
                nums[nums.size()-1] = nums[nums.size()-1] * stoi(s.substr(start, end-start));
            }else{
                nums.push_back(stoi(s.substr(start, end-start)));
            }
            start = end;
        }
        for(int i = 0; i < ops.size(); ++i){
            if(ops[i] == '-'){
                nums[0] -= nums[i+1];
            }else{
                nums[0] += nums[i+1];
            }
        }
        return nums[0];
    }

    bool isDigit(char ch){
        return ch <= '9' && ch >= '0';
    }
};
/*
第二次做：
我说我怎么做的这么麻烦呢， 原来是人家里面没有括号啊。。。

另外就是，这一版写的还可以。忘记了两件事：1， 忘了更新index；2，忘了最后把剩下的栈里的内容再计算一遍。
*/
class Solution {
private:
    string deleteBlanks(const string s) {
        string ans;
        for (auto ch : s) {
            if (ch != ' ') ans.push_back(ch);
        }
        return ans;
    }

    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    bool isOps(char ch) {
        return ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

public:
    int calculate(string s) {
        s = deleteBlanks(s);

        stack<char> ops;
        stack<int> nums;
        int index = 0;
        while (index < s.size()) {
            if (isOps(s[index])) {
                ops.push(s[index]);
                index++;
            } else if (isDigit(s[index])) {
                int end = index+1;
                while (end < s.size() && isDigit(s[end])) end++;
                int num2 = stoi(s.substr(index, end-index));

                while (ops.size() > 0 && (ops.top() == '*' || ops.top() == '/')) {
                    int num1 = nums.top(); nums.pop();
                    if (ops.top() == '*') {
                        num2 = num1 * num2;
                    } else {
                        num2 = num1 / num2;
                    }
                    ops.pop();
                }
                nums.push(num2);
                index = end;
            } else {
                int ans = 0;
                while (ops.size() > 0 && ops.top() != '(') {
                    if (ops.top() == '+') ans += nums.top();
                    else ans -= nums.top();
                    ops.pop();
                    nums.pop();
                }
                ans += nums.top();
                nums.pop();

                if (ops.size() > 0 && ops.top() == '*' || ops.top() == '/') {
                    int num1 = nums.top();
                    nums.pop();
                    if (ops.top() == '*') {
                        ans = ans * num1;
                    } else {
                        ans = num1 / ans;
                    }
                }
                nums.push(ans);
                index++;
            }
        }

        int ans = 0;
        while (ops.size() > 0) {
            if (ops.top() == '+') ans += nums.top();
            else ans -= nums.top();
            nums.pop(); ops.pop();
        }
        ans += nums.top();
        return ans;
    }
};
/*
 * ok
 */
class Solution {
private:
    string deleteBlanks(const string s) {
        string ans;
        for (auto ch : s) {
            if (ch != ' ') ans.push_back(ch);
        }
        return ans;
    }

    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

public:
    int calculate(string s) {
        s = deleteBlanks(s);
        if (s.size() == 0) return 0;

        int index = 0;
        while (index < s.size() && !isOperator(s[index])) index++;
        int ans = stoi(s.substr(0, index)), last = ans;
        while (index < s.size()) {
            char op = s[index];
            index++;
            int next = index+1;
            while (next < s.size() && !isOperator(s[next])) next++;
            int right = stoi(s.substr(index, next-index));

            if (op == '*') {
                ans -= last;
                last *= right;
                ans += last;
            } else if (op == '/') {
                ans -= last;
                last /= right;
                ans += last;
            } else if (op == '+') {
                ans += right;
                last = right;
            } else {
                ans -= right;
                last = -right;
            }
            index = next;
        }
        return ans;
    }
};
