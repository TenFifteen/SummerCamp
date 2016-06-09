#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printArray(const vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int tmp = arr[n-1];
    int index = n-2;
    while (index >= 0 && arr[index] > tmp) {
        arr[index+1] = arr[index];
        index--;
        printArray(arr);
    }
    
    arr[index+1] = tmp;
    printArray(arr);
    
    return 0;
}
