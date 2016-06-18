/*
虽然一开始想的贪心的策略没有啥问题，只是实施起来好像稍微复杂度高一点。
原来的代码见尾部注释。
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 0) { // segmentation fault.
            cout << 0 << endl;
            continue;
        }
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        map<int, multiset<int>> hash;
        for (int i = 0; i < n; ++i) {
            auto it = hash.find(arr[i]-1);
            if (it != hash.end() && it->second.size() > 0) {
                int top = *it->second.begin();
                hash[arr[i]].insert(top+1);
                it->second.erase(it->second.find(top));
            } else {
                hash[arr[i]].insert(1);
            }
        }

        int ans = INT_MAX;
        for (auto p : hash) {
            if (p.second.size() == 0) continue;
            ans = min(ans, *p.second.begin());
        }
        cout << ans << endl;
    }
    return 0;
}

/*
const int maxn = 1000004;
int arr[maxn];

int main() {
    int T;
    scanf("%d", &T);
    //cin >> T;
    //ios::sync_with_stdio(false);
    while (T--) {
        int n;
        //cin >> n;
        scanf("%d", &n);
        if (n == 0) {
            //cout << 0 << endl;
            printf("%d\n", 0);
            continue;
        }
        //vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            //cin >> arr[i];
            scanf("%d", &arr[i]);
        }

        sort(arr, arr+n);

        deque<int> ms;
        int index = 0;
        while (arr[index] == arr[0]) {
            ms.push_back(1);
            index++;
        }

        int ans = INT_MAX;
        int last = arr[0];
        while (index < n) {
            if (arr[index] != last+1) {
                ans = min(ms[0], ans);
                ms.clear();
                int next = index;
                while (next < n && arr[next] == arr[index]) {
                    next++;
                    ms.push_back(1);
                }
                last = arr[index];
                index = next;
            } else {
                int next = index, cnt = 0;
                while (next < n && arr[next] == arr[index]) {
                    cnt++;
                    next++;
                }
                index = next;
                last++;

                if (cnt > ms.size()) {
                    for (int i = 0; i < cnt; ++i) ms[i]++;
                    int addNum = cnt - ms.size();
                    for (int i = 0; i < addNum; ++i) ms.push_front(1);
                    //sort(ms.begin(), ms.end());
                } else {
                    int popNum = ms.size() - cnt;
                    for (int i = 0; i < popNum; ++i) {
                        ans = min(ms.back(), ans);
                        ms.pop_back();
                    }
                    for (int i = 0; i < ms.size(); ++i) ms[i]++;
                }
            }
        }
        ans = min(ans, ms[0]);
        //cout << ans << endl;
        printf("%d\n", ans);
    }
    return 0;
}
*/
