#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quicksort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    
    int i = left, j = left;
    while (i < right) {
        if (arr[i] < arr[right]) swap(arr[i++], arr[j++]);
        else i++;
    }
    swap(arr[j], arr[right]);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    quicksort(arr, left, j-1);
    quicksort(arr, j+1, right);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    quicksort(arr, 0, n-1);
    
    return 0;
}
