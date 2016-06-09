#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;

    int a = 0, b = 0, tmp;
    for(int a_i = 0;a_i < n;a_i++){
        for(int a_j = 0;a_j < n;a_j++){
            cin >> tmp;
            a += a_i == a_j ? tmp : 0;
            b += a_i + a_j == n-1 ? tmp : 0;

        }
    }

    cout << abs(a - b) << endl;
    return 0;
}

