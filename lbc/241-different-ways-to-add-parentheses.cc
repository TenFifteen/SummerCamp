/*
题目大意：
给定一个算术表达式的字符串，求出其所有可能的结果。（加括号的方式）两种结果相同的话，并不需要去重。

解题思路：
其实这个就跟求二叉树的种类是一样的。

遇到的问题：
一开始用的是动态规划的方法，感觉可以省一些时间。虽然多一些空间，感觉还是可以的，竟然超过了内存限制。
只好改成了递归求解。一次通过。

再次阅读：
有一个很直观的分治的递归实现方案：
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1));
                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);    
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};
下面这个是对上面这个做一点点小优化的地方，不过虽然时间有话了一些，但是空间大了很多：
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> dpMap;
        return computeWithDP(input, dpMap);
    }

    vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1, result2;
                string substr = input.substr(0, i);
                // check if dpMap has the result for substr
                if (dpMap.find(substr) != dpMap.end())
                    result1 = dpMap[substr];
                else
                    result1 = computeWithDP(substr, dpMap);

                substr = input.substr(i + 1);
                if (dpMap.find(substr) != dpMap.end())
                    result2 = dpMap[substr];
                else
                    result2 = computeWithDP(substr, dpMap);

                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        // save to dpMap
        dpMap[input] = result;
        return result;
    }
};
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        vector<int> numbers;
        vector<char> ops;
        if(input.size() == 0)return ans;
        int tmp = input[0]-'0';
        for(int i = 1; i < input.size(); ++i){
            if(input[i] >= '0' && input[i] <= '9'){
                tmp *= 10;
                tmp += input[i]-'0';
            }else{
                numbers.push_back(tmp);
                tmp = input[i+1]-'0';
                ops.push_back(input[i]);
                i++;
            }
        }
        numbers.push_back(tmp);
        if(ops.size() == 0)return numbers;
        
        //method2
        return sub2(numbers, ops, 0, ops.size());

        //method1, memory limit exceed
        vector<vector<vector<int>>> dp(ops.size(), vector<vector<int>>(ops.size()));
        for(int i = 0; i < ops.size(); ++i){
            dp[i][i].push_back(sub(numbers[i], numbers[i+1], ops[i]));
        }
        for(int i = 1; i < ops.size(); ++i){
            for(int j = 0; j < ops.size()-i; ++j){
                for(int k = j; k <= j+i; ++k){
                    if(k == j){
                        for(int m = 0; m < dp[j+1][j+i].size(); ++m){
                            dp[j][i].push_back(sub(numbers[j], dp[j+1][j+i][m], ops[j]));
                        }
                    }else if(k == j+i){
                        for(int m = 0; m < dp[j][j+i-1].size(); ++m){
                            dp[j][i].push_back(sub(dp[j][j+i-1][m], numbers[k+1], ops[k]));
                        }
                    }else{
                        for(int m = 0; m < dp[j][k-1].size(); ++m){
                            for(int n = 0; n < dp[k+1][j+i].size(); ++n){
                                dp[j][i].push_back(sub(dp[j][k-1][m], dp[k+1][j+i][n], ops[k]));
                            }
                        }
                    }
                }
            }
        }
        return dp[0][ops.size()-1];
    }
    
    vector<int> sub2(vector<int> &numbers, vector<char> &ops, int left, int right){
        vector<int> ans;
        if(left == right){
            ans.push_back(numbers[left]);
            return ans;
        }
        
        for(int i = left; i < right; ++i){
            auto ret_l = sub2(numbers, ops, left, i);
            auto ret_r = sub2(numbers, ops, i+1, right);
            for(auto l:ret_l){
                for(auto r:ret_r){
                    ans.push_back(sub(l, r, ops[i]));
                }
            }
        }
    }
    
    int sub(int a, int b, char op){
        switch(op){
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
        }
    }
};
/*
第二次做：
这次的代码比之前简洁多了。
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        if (input.size() == 0) return ans;
        
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '-' || input[i] == '+' || input[i] == '*') {
                auto left = diffWaysToCompute(input.substr(0, i));
                auto right = diffWaysToCompute(input.substr(i+1));
                for (auto l : left) {
                    for (auto r : right) {
                        if (input[i] == '-') ans.push_back(l-r);
                        else if (input[i] == '+') ans.push_back(l+r);
                        else ans.push_back(l*r);
                    }
                }
            }
        }
        
        if (ans.size() == 0) ans.push_back(stoi(input));
        return ans;
    }
};