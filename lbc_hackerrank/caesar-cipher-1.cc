/*
这个题目的教训就是关于char的范围。
以前一直没有注意，char的范围是-128~127的。
所以如果给一个字母加上一个数字，很有可能就超过了范围了。
尤其是小写字母的编号还比较大。
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    char str[128];
    cin >> str;
    int k;
    cin >> k;
    k %= 26;
    k = 26-k;
    for (int i = 0; i < n; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= k;
            if (str[i] < 'a') str[i] += 26;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] -= k;
            if (str[i] < 'A') str[i] += 26;
        }
    }
    cout << str << endl;
    return 0;
}
