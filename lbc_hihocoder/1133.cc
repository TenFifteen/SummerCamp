#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

const int maxn = 1000002;
LL arr[maxn];

LL find_min_k(int left, int right, int k) {
    if (left > right) return -1;
    if (k < left || k > right) return -1;
    if (left == right) return arr[left];

    int mid = arr[left];
    int L = left, R = right;
    while (L < R) {
        while (L < R && arr[R] > mid) R--;
        arr[L] = arr[R];
        while (L < R && arr[L] <= mid) L++;
        arr[R] = arr[L];
    }
    arr[L] = mid;

    if (L == k) {
        return arr[L];
    } else if (L < k) {
        return find_min_k(L+1, right, k);
    } else {
        return find_min_k(left, L-1, k);
    }
}

int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
        }
        printf("%lld\n", find_min_k(0, n-1, k-1));
    }
    return 0;

}
