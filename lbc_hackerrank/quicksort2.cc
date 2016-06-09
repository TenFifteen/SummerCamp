/*
题目太挫了，非得保证顺序啊。
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quicksort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    int val = arr[left];
    int i = left, j = i, k = right;
    while (i <= k) {
        if (arr[i] < val) {
            swap(arr[i++], arr[j++]);
        } else if (arr[i] > val) {
            swap(arr[i], arr[k--]);
        } else {
            i++;
        }
    }
    quicksort(arr, left, k-1);
    quicksort(arr, k+1, right);
    for (int i = left; i <= right; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quicksortII(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    vector<int> tmp(right-left+1);
    int index = 0;
    for (int i = left; i <= right; ++i) {
        if (arr[i] < arr[left]) tmp[index++] = arr[i];
    }
    index = tmp.size()-1;
    for (int i = right; i >= left; --i) {
        if (arr[i] > arr[left]) tmp[index--] = arr[i];
    }
    tmp[index] = arr[left];
    
    for (int i = 0; i < tmp.size(); ++i) {
        arr[left+i] = tmp[i];
    }
    
    quicksortII(arr, left, left+index-1);
    quicksortII(arr, left+index+1, right);
    for (int i = left; i <= right; ++i) {
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
    quicksortII(arr, 0, n-1);
    return 0;
}
