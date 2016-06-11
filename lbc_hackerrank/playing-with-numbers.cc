/*
这道题目还是算是有点难度的，幸好想出来了这么个做法。
纪念一下。
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find_greater_and_equal(const vector<int> &arr, long long val) {
    int left = 0, right = arr.size()-1;
    while (left < right) {
        int mid = (left+right)/2;
        if (arr[mid] >= val) right = mid;
        else left = mid+1;
    }
    if (arr[left] < val) left++;
    return left + 1; // to turn to sum index
}

int find_smaller_and_equal(const vector<int> &arr, long long val) {
    int left = 0, right = arr.size()-1;
    while (left < right) {
        int mid = (left+right+1)/2;
        if (arr[mid] <= val) left = mid;
        else right = mid-1;
    }
    if (arr[left] > val) left--;
    return left + 1; // to turn to sum index
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    vector<long long> sum(n+1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1] + arr[i-1];
    }
    
    int larger_than_zero = find_greater_and_equal(arr, 1);
    int smaller_than_zero = find_smaller_and_equal(arr, -1);
    
    long long now;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        long long q;
        cin >> q;
        now += q;
        
        long long cur_sum = 0;
        if (now > 0) {
            int smaller = find_smaller_and_equal(arr, -now);
            cur_sum += -sum[smaller] - smaller*now;
            cur_sum += sum[smaller_than_zero] - sum[smaller] + now*(smaller_than_zero-smaller);
            cur_sum += sum[n] - sum[smaller_than_zero] + now*(n-smaller_than_zero);
        } else if (now < 0) {
            int larger = find_greater_and_equal(arr, -now);
            cur_sum += sum[n] - sum[larger-1] + now*(n-larger+1);
            cur_sum += -sum[larger-1] + sum[larger_than_zero-1] - now*(larger-larger_than_zero);
            cur_sum += -sum[larger_than_zero-1] - now*(larger_than_zero-1);
        } else {
            cur_sum += sum[n] - sum[larger_than_zero-1];
            cur_sum += -sum[smaller_than_zero];
        }
        cout << cur_sum << endl;
    }
    return 0;
}
