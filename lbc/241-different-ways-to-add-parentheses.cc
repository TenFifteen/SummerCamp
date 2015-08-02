/*
题目大意：
给定一个算术表达式的字符串，求出其所有可能的结果。（加括号的方式）两种结果相同的话，并不需要去重。

解题思路：
其实这个就跟求二叉树的种类是一样的。

遇到的问题：
一开始用的是动态规划的方法，感觉可以省一些时间。虽然多一些空间，感觉还是可以的，竟然超过了内存限制。
只好改成了递归求解。一次通过。
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