/*
题目：27 % 子数组求和 II 困难

题目大意：
给定一个数组，都是正数。给定一个区间。问所有的数组的子数组的和在该区间中的个数是多少？

解题思路：
先计算出所有元素的前缀和。
然后分别计算以第i个节点为区间右边界的满足条件的区间的个数。
找边界的时候用二分。

遇到的问题：
这个题做的时间可是够久的了。
一开始没有思路。然后看别人做的，有了思路
然后开始调试，搞了好久。
最后还是误打误撞正确了。
不过代码好丑。回头一定要好好重新写一下。
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        vector<long long> sum(A.size());
        
        sum[0] = A[0];
        for (int i = 1; i < A.size(); ++i) {
            sum[i] = A[i] + sum[i-1];
        }
        
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (sum[i] < start) continue;
            if (A[i] > end) continue;
            int left = 0, right = i;
            while (left < right) {
                int mid = left + (right-left)/2;
                if (sum[i]-sum[mid] > end) {
                    left = mid+1;
                } else if (sum[i]-sum[mid] < start) {
                    right = mid-1;
                } else {
                    right = mid;
                }
            }
            
            int rleft = 0, rright = i;
            while (rleft < rright) {
                int mid = rleft + (rright-rleft+1)/2;
                if (sum[i]-sum[mid] < start) {
                    rright = mid-1;
                } else if (sum[i]-sum[mid] > end) {
                    rleft = mid+1;
                } else {
                    rleft = mid;
                }
            }
            
            if (sum[i] <= end) {
                left = 0;
                if (sum[i] - sum[rleft] <= end && sum[i] - sum[rleft] >= start) {
                    rleft++;
                }
            }
            ans += (rleft - left + 1);
        }
        
        return ans;
    }

     
    //超时
    int subarraySumII2(vector<int>& A, int start, int end) {
        // Write your code here
        vector<vector<int>> sum(A.size(), vector<int>(A.size()));
        
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum[i][0] = A[i];
            if (sum[i][0] >= start && sum[i][0] <= end) {
                ans++;
            }
        }
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j+i < A.size(); ++j) {
                sum[j][i] = sum[j][i-1] + A[j+i];
                if (sum[j][i] >= start && sum[j][i] <= end) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
