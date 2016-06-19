/*
天啦，这题目已经超出了我的能力范围了。实在是不会做啊。只能看题解，题解能看懂
就不错了。
参考：http://www.cnblogs.com/Ritchie/p/5388870.html
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            if (num == 1) cnt1++;
            else cnt2++;
            ans ^= num;
        }
        //cout << ans << " " << cnt1 << " " << cnt2 << endl;
        if ((ans == 0 && cnt2 == 0) || (ans != 0 && cnt2 != 0)) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    return 0;
}
