#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;

    int tmp;
    int po = 0, ng = 0, zo = 0;
    for(int arr_i = 0;arr_i < n;arr_i++){
        cin >> tmp;
        if (tmp == 0) zo++;
        else if (tmp > 0) po++;
        else ng++;
    }


    printf("%.6f\n%.6f\n%.6f\n", (double)po/n, (double)ng/n, (double)zo/n);
    return 0;
}

