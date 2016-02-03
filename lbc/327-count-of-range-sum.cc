/*
题目大意：
给定一个数组，一个区间[low, upper]
问所有的数组的子数组的和在该区间的个数

解题思路：
最简单的肯定是直接计算出每个区间的和，然后判断一下。n*n的复杂度。
然后就死活想不出来别的解法了。
看到别人的思路之后感觉大开眼界啊，直接做了一个题，是判断每个数字后面有多少小于该数字的数。
然后形式化就是arr[i]-arr[j] (j > i && j < n)的个数
然后这个问题的形式化就是sum[j]-sum[i] <= upper && sum[j]-sum[i] >= low (j > i && j < n)
然后就又可以用mergeSort的变形来解了。

遇到的问题：
一开始把upper函数写成了lower了，所以一直错。

再次阅读：
思路已经是借鉴的最好的思路了。当然了这个题目，还有之前那个判断数字后面有多少小于该数字的数
的题目都是一样的解法，既可以用mergerSort也可以用SegmentTree
*/
class Solution {
private:
    int lower(vector<long long> &sum, int left, int right, long long val) {
        int ans = right+1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (sum[mid] < val) {
                left = mid+1;
            } else {
                ans = min(ans, mid);
                right = mid-1;
            }
        }
        return ans;
    }
    
    int upper(vector<long long> &sum, int left, int right, long long val) {
        int ans = right+1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (sum[mid] <= val) {
                left = mid+1;
            } else {
                ans = min(ans, mid);
                right = mid-1;
            }
        }
        return ans;
    }
    
    int mergeSort(vector<long long> &sum, int left, int right, int LOW, int UP) {
        if (left >= right) return 0;
        
        int L = left, R = right;
        
        int mid = (left + right) >> 1;
        int ans = 0;
        ans += mergeSort(sum, left, mid, LOW, UP);
        ans += mergeSort(sum, mid+1, right, LOW, UP);
        
        for (int i = left; i <= mid; ++i) {
            int low = lower(sum, mid+1, right, sum[i]+LOW);
            int up = upper(sum, mid+1, right, sum[i]+UP);
            ans += up - low;
        }
        
        vector<long long> tmp(sum.begin()+L, sum.begin()+R+1);
        int i = L, j = 0, k = mid+1-L;
        while (j + L <= mid && k+L <= right) {
            if (tmp[j] > tmp[k]) {
                sum[i++] = tmp[k++];
            } else {
                sum[i++] = tmp[j++];
            }
        }
        
        while (j + L <= mid) {
            sum[i++] = tmp[j++];
        }
        
        return ans;
    }
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        if (nums.size() < 1) return 0;
        
        vector<long long> sum(nums.size()+1, 0);
        for (int i = 1; i < sum.size(); ++i) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        
        int ans =  mergeSort(sum, 0, sum.size()-1, lower, upper);
        
        return ans;
    }
    
    int countRangeSum2(vector<int> &nums, int lower, int upper) {
        if (nums.size() < 1) return 0;
        
        vector<long long> sum(nums.size());
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] = nums[i] + sum[i-1];
        }
        
        int cnt = 0;
        for (int i = 0; i < sum.size(); ++i) {
            for (int j = i; j < sum.size(); ++j) {
                if (i == 0) {
                    if (sum[j] >= lower && sum[j] < upper) cnt++;
                } else {
                    if (sum[j]-sum[i-1] >= lower && sum[j]-sum[i-1] < upper) cnt++;
                }
            }
        }
        
        return cnt;
    }
};