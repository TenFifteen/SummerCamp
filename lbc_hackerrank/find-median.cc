#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findKth(vector<int> &arr, int left, int right, int K) {
    if (left >= right) return arr[left];
    
    int i = left, j = i, k = right-1;
    while (i <= k) {
        if (arr[i] < arr[right]) swap(arr[i++], arr[j++]);
        else if (arr[i] > arr[right]) swap(arr[i], arr[k--]);
        else i++;
    }
    swap(arr[k+1], arr[right]);
    
    if (k+1 == K) return arr[k+1];
    if (k+1 > K) return findKth(arr, left, k, K);
    else return findKth(arr, k+2, right, K);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << findKth(arr, 0, n-1, n/2) << endl;
    return 0;
}
