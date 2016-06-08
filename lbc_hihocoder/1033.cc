/*
题目大意：
感觉这道题真的是太经典了，以前经常在比赛中见到，但是却从来都是束手无策的。
现在终于知道了这种题目叫做“数位dp”，而且是有模板可以来解的。下面的实现过程
就接近于模板实现，很多题目都可以转化成这种过程来解的。
*/
#include <iostream>
using namespace std;

typedef long long LL;
struct Node {
    LL sum, cnt;
    Node(): sum(0), cnt(0) {}
    Node& operator=(const Node &n) {
        sum = n.sum;
        cnt = n.cnt;
    }
};

LL L, R, k;
LL bit[20], base[20], bit_len, cur_len;
Node dp[20][400];
LL mod = 1000000007;

void reset(LL val) {
    for (LL i = 0; i < 20; ++i) {
        for (LL j = 0; j < 400; ++j) {
            dp[i][j].cnt = val;
            dp[i][j].sum = 0;
        }
    }
}

Node dfs(LL pos, LL target, bool limit) {
    Node ret;
    if (pos == 0) {
        if (target == 200) ret.cnt = 1;
        return ret;
    }

    if (limit == false && dp[pos][target].cnt >= 0) return dp[pos][target];

    LL tail = limit ? bit[pos] : 9;
    LL sgn = (cur_len - pos) % 2 ? -1 : 1;
    LL head = pos == cur_len ? 1 : 0;

    for (LL i = head; i <= tail; ++i) {
        Node tmp = dfs(pos-1, target-i*sgn, limit && i == bit[pos]);
        if (tmp.cnt > 0) {
            ret.cnt += tmp.cnt;
            ret.cnt %= mod;
            ret.sum += tmp.cnt * base[pos] % mod * i % mod;
            ret.sum %= mod;
            ret.sum += tmp.sum;
            ret.sum %= mod;
        }
    }
    if (limit == false) dp[pos][target] = ret;
    return ret;
}

LL cal(LL end, LL K) {
    LL ans = 0;
    if (end <= 0) return ans;

    bit_len = 0;
    while (end) {
        bit_len++;
        bit[bit_len] = end % 10;
        end /= 10;
    }


    for (LL i = 1; i <= bit_len; ++i) {
        reset(-1);
        cur_len = i;
        ans += dfs(i, K+200, i == bit_len).sum;
        ans %= mod;
    }

    return ans;
}

int main() {
    base[1] = 1;
    for (LL i = 2; i < 20; ++i) {
        base[i] = base[i-1]*10%mod;
    }

    cin >> L >> R >> k;
    cout << (cal(R, k) - cal(L-1, k) + mod) % mod << endl;
    return 0;
}
