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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    for (int i = 1; i < n; ++i) {
        int tmp = arr[i];
        int index = i-1;
        while (index >= 0 && arr[index] > tmp) {
            arr[index+1] = arr[index];
            index--;
        }
        arr[index+1] = tmp;
    }
    
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
