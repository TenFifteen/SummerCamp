#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int maxn = 1000002;
LL arr[maxn];

int b_search(int left, int right, LL val) {
    int i = left, j = left, k = right;
    while (i <= k) {
        if (arr[i] < val) {
            swap(arr[j++], arr[i++]);
        } else if (arr[i] == val) {
            i++;
        } else {
            swap(arr[i], arr[k--]);
        }
    }

    return j == k ? j : -1;
}

int main() {
    LL n, k;
    while (scanf("%lld%lld", &n, &k) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &arr[i]);
        }
        printf("%d\n", b_search(1, n, k));
    }
    return 0;
}
