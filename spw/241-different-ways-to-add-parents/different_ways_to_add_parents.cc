#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Given a string of numbers and operators, return all possible results
 *          from computing all different possible ways to group numbers and operators
 *          The valid operators are + - and *
 * Solve: divide and conquer
 * Tips: After divide, if answer is empty, then we can determine that the input is a
 *       number.
 */
class Solution {
    public:
        vector<int> diffWaysToCompute(string input) {
            vector<int> ans;
            int n = input.size();

            for (int i = 0; i < n; ++i) {
                if (input[i] == ' ') {
                    continue;
                } else if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                    vector<int> left = diffWaysToCompute(input.substr(0, i));
                    vector<int> right = diffWaysToCompute(input.substr(i+1));
                    for (auto l : left) {
                        for (auto r : right) {
                            if (input[i] == '+') {
                                ans.push_back(l + r);
                            } else if (input[i] == '-') {
                                ans.push_back(l - r);
                            } else {
                                ans.push_back(l * r);
                            }
                        }
                    }
                }
            }

            if (ans.empty())
                ans.push_back(atoi(input.c_str()));
            return ans;
        }
}

int main() {
    vector<int> ans = diffWaysToCompute("2-1-1");
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
         cout << *it << endl;
    }

    return 0;
}

class Solution {
private:
    int cal(char op, int a, int b) {
        if (op == '+') return a+b;
        else if (op == '-') return a-b;
        else return a*b;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        int i = 0, n = input.size();

        vector<int> ans;
        if (n == 0) return ans;
        for (int i = 0; i < n; ++i) {
            if (input[i] == '*' || input[i] == '+' || input[i] == '-') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));

                for (int a : left) {
                    for (int b : right) {
                        ans.push_back(cal(input[i], a, b));
                    }
                }
            }
        }

        if (ans.empty()) {
            ans.push_back(stoi(input));
        }

        return ans;
    }
};
