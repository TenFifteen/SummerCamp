/**
 * Problem: Little Bob loves chocolate, and he goes to a store with N
 *          in his pocket. The price of each chocolate is . The store
 *          offers a discount: for every  wrappers he gives to the store,
 *          he gets one chocolate for free. How many chocolates does Bob get to eat?
 * Solve: replace the aside as possible as you can.
 * Tips: but there can be some changes left.
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, c, m;
        cin >> n >> c >> m;

        int ans = n / c;
        int aside = ans;
        while (aside >= m) {
            ans += aside / m;
            aside = aside / m + aside % m;
        }

        cout << ans << endl;
    }
    return 0;
}

