/*
#include <iostream>
using namespace std;

int main() {
    int n, m, L;
    while (cin >> n >> m >> L) {
        int l, r, t, b;
        cin >> l >> r >> t >> b;

        int maxWidth = max(l, m-r);
        int maxHeight = max(t, n-b);
        int lenWidth = r-l;
        int lenHeight = b-t;

        int ans = 0;
        for (int width = 1; width <= m; ++width) {
            int height = (L - 2*width) / 2;
            if (height < 1) break;
            height = min(height, n);

            int now = width * height;
            int hole_width = 0;
            if (width > maxWidth) {
                hole_width = min(lenWidth, width-maxWidth);
            }
            int hole_height = 0;
            if (height > maxHeight) {
                hole_height = min(lenHeight, height-maxHeight);
            }

            if (hole_width == lenWidth && hole_height == 0) continue;
            if (hole_height == lenHeight && hole_width == 0) continue;

            now -= hole_width * hole_height;
            cout << "width = " << width << "; height = " << height << "; now = " << now << endl;
            ans = max(ans, now);
        }

        cout << ans << endl;
    }
}

我自己的想法虽然没有太大问题，但是想漏了一种情况，所以是错的。
虽然不知道为啥一定要按照答案那样遍历，不过感觉上的确是无懈可击。

通过这道题还是学到了挺多东西的，题目不能乱想，要考虑清楚各种情况再写。
*/

#include <iostream>
using namespace std;

int main() {
    int n, m , L;
    while (cin >> n >> m >> L) {
        int l, r, t, b;
        cin >> l >> r >> t >> b;

        if (l < m-r) {
            int tmp = r;
            r = m-l;
            l = m-tmp;
        }

        if (t < n-b) {
            int tmp = b;
            b = n-t;
            t = n-tmp;
        }

        int ans = 0;
        for (int i = 1; i <= m && i < L/2; ++i) {
            for (int j = 1; j <= n && (j+i)*2 <= L; ++j) {
                int cur = 0;
                if (i <= l || j <= t) {
                    cur = i*j;
                } else if (i >= r && j >= b) {
                    cur = i*j - (r-l)*(b-t);
                } else if (i <= r && j <= b) {
                    cur = i*j - (i-l)*(j-t);
                } else if (i < r && j > b) {
                    int tmp = min(i-l, r-i);
                    if ((i+j+tmp) * 2 <= L) cur = i*j - (i-l)*(b-t);
                } else if (i > r && j < b) {
                    int tmp = min(j-t, b-j);
                    if ((i+j+tmp) * 2 <= L) cur = i*j - (r-l)*(j-t);
                }

                ans = max(ans, cur);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
