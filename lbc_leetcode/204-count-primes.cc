/*
题目大意：
给定一个n，问小于n的数里面有多少个素数

解题思路：
筛选法找素数

遇到的问题：
一开始当做了小于等于n了。

再次阅读：
简单的找素数的代码。
之前用的是筛法找素数，感觉代码还是很好的了。
然后看了一下DISCUSS，也就是这样了。
*/
class Solution {
public:
    int countPrimes(int n) {
        vector<int> flag(n, true);
        int ret = 0;
        for(int i = 2; i < n; ++i){
            if(flag[i]){
                ret++;
                for(int j = i; j < n; j += i){
                    flag[j] = false;
                }
            }
        }
        return ret;
    }
};
/*
第二次做：
简单题，不过还是犯了两个错误。
第一个是在第二个for前面忘记了加上条件了。
第二个是看错了题目要求是小于了，给看成了小于等于了。
*/
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> ans(n, true);

        for (int i = 2; i < n; ++i) {
            if (ans[i]) for (int j = i*2; j <= n; j += i) {
                ans[j] = false;
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (ans[i]) cnt++;
        }
        return cnt;
    }
};
/*
 * it's ok
 */
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;

        vector<bool> prime(n, true);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (prime[i] == false) continue;
            ans++;
            for (int j = i+i; j < n; j += i) {
                prime[j] = false;
            }
        }
        return ans;
    }
};
