/*
 * 感觉这道题目根本就不是dp嘛，完全就是贪心了。骗子。
 * 我已开始只想到了直接减到arr[0]这种情况，最后还是看了这篇帖子才知道的最终的解法：
 * http://winoros.logdown.com/posts/245627-hackerrank-equal
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        for (int k = 0; k < 5; ++k) {
            int this_ans = 0;
            for (int i = 0; i < n; ++i) {
                long long diff = arr[i]-arr[0]+k;
                long long cnt = 0;
                cnt += diff / 5;
                diff %= 5;
                cnt += diff / 2;
                diff %= 2;
                cnt += diff;
                this_ans += cnt;
            }
            ans = min(ans, this_ans);
        }
        cout << ans << endl;
    }
    return 0;
}
