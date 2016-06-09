#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int insertSort(vector<int> arr) {
    int total = 0;
    for (int i = 1; i < arr.size(); ++i) {
        int tmp = arr[i];
        int index = i-1;
        while (index >= 0 && arr[index] > tmp) {
            swap(arr[index+1], arr[index]);
            total++;
            index--;
        }
        arr[index+1] = tmp;
    }
    return total;
}

int quickSort(vector<int> &arr, int left, int right) {
    if (left >= right) return 0;
    
    int i = left, j = left, total = 0;
    while (i < right) {
        if (arr[i] > arr[right]) i++;
        else {
            swap(arr[i++], arr[j++]);
            total++;
        }
    }
    swap(arr[j], arr[right]);
    total++;
    
    total += quickSort(arr, left, j-1);
    total += quickSort(arr, j+1, right);
    return total;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    //cout << insertSort(arr) << endl;
    //cout << quickSort(arr, 0, n-1) << endl;
    cout << insertSort(arr) - quickSort(arr, 0, n-1) << endl;
    return 0;
}
