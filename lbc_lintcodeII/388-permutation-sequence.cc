/*
题目大意：
求第k个排列。

解题思路：
见代码。

遇到的问题：
没有问题。
不过感觉代码稍微有一点点乱。。
*/
class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        vector<int> buf(n);
        buf[0] = 1;
        for (int i = 1; i < n; ++i) {
            buf[i] = buf[i-1] * i;
        }
        
        vector<bool> numbers(n, false);
        string ans;
        k--;
        
        for (int i = 0; i < n; ++i) {
            int now = k / buf[n-i-1];
            k %= buf[n-i-1];
            int cnt = 0;
            
            for (int j = 0; j < n; ++j) {
                if (numbers[j] == false) {
                    cnt++;
                    if (cnt > now) {
                        numbers[j] = true;
                        ans.push_back(j + '1');
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};
