/*
 * 说实话，这道题存在一定的bug，见后面代码中的注释。
 * 不过一开始还是想的有问题，以为是背包问题呢，结果一看sum太大了。根本不行。
 * 最后还是看了别人的思路。
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getAnswer(vector<long long> &ps, int left, int right) {
    if (left >= right) return 0;
    long long sum = (ps[right] - ps[left-1]) / 2;
    if (sum * 2 != ps[right] - ps[left-1]) return 0;

    int L = left, R = right-1;
    while (L < R) {
        int mid = (L+R)/2;
        if (ps[right] - ps[mid] > sum) L = mid+1;
        else if (ps[right] - ps[mid] < sum) R = mid-1;
        else L = R = mid;
    }

    if (ps[right] - ps[L] != sum) return 0;
    return max(getAnswer(ps, left, L), getAnswer(ps, L+1, right)) + 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> ps(n+1);
        for (int i = 1; i <= n; ++i) {
            int num;
            cin >> num;
            ps[i] = ps[i-1] + num;
        }
        if (ps[n] == 0) cout << n-1 << endl;// to deal with all 0s.
                                            // but I don't think so. for example 1, -1, 1, -1.
                                            // it's the problem's bug.
                                            // unless all number be non-negtive.
        else cout << getAnswer(ps, 1, n) << endl;
    }
    return 0;
}
