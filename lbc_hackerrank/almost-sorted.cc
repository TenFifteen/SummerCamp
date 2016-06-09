#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isSorted(const vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i-1]) cnt++;
    }
    
    if (cnt == 0) {
        cout << "yes" << endl;
    } else {
        if (cnt == 1) {
            int index = 1;
            while (arr[index] >= arr[index-1]) index++;
            if ((index == 1 || arr[index] >= arr[index-2]) && (index == n-1 || arr[index-1] <= arr[index+1])) {
                cout << "yes" << endl;
                cout << "swap " << index << " " << index+1 << endl;
            } else {
                cout << "no" << endl;
            }
        } else if (cnt == 2) {
            int i1 = 1, i2 = n-1;
            while (arr[i1] >= arr[i1-1]) i1++;
            while (arr[i2] >= arr[i2-1]) i2--;
            i1--;
            
            if (arr[i1] >= arr[i2-1] && (i2 == n || arr[i1] <= arr[i2+1]) &&
               arr[i2] >= arr[i1-1] && arr[i2] <= arr[i1+1]) {
                cout << "yes" << endl;
                cout << "swap " << i1+1 << " " << i2+1 << endl;
            } else {
                cout << "no" << endl;
            }
        } else {
            int i1 = 1, i2 = n-1;
            while (arr[i1] >= arr[i1-1]) i1++;
            while (arr[i2] >= arr[i2-1]) i2--;
            i1--;
            int left = i1, right = i2;
            while (left < right) {
                swap(arr[left++], arr[right--]);
            }
            if (isSorted(arr)) {
                cout << "yes" << endl;
                cout << "reverse " << i1+1 << " " << i2+1 << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
    
    return 0;
}
