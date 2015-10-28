/*
题目：11 % 连续子数组求和 II 中等

题目大意：
给定一个数组，问其连续子段和最大是多少？数组可以循环

解题思路：
先按照正常的找到不循环的最大连续字段和。
然后找到最小连续字段和，用总和减去最小的和然后跟之前找到的最大的字段和比较。
这里需要注意到最小的字段和有可能是全部数组的情况。

遇到的问题：
问题太多了。本来以为是一个中等题目，应该很多A掉。结果试了三种方法才解决掉。

前两种访问都有一种问题就是，如果计算的时候恰好所有的字段和都是正的，例如：4，-1， 3
然后最后一种，如果遇到的全是负的也需要特殊处理，例如：-10，-20，-30，-5，-10， -20， -5
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        int left, right;
        int max = INT_MIN;
        int last = 0;
        int sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            if (sum > max) {
                max = sum;
                left = last;
                right = i;
            }
            if (sum <= 0) {
                last = i+1;
                sum = 0;
            }
        }
        
        int min = INT_MAX;
        last = 0;
        sum = 0;
        int mleft, mright;
        int total = 0;
        for (int i = 0; i < A.size(); ++i) {
            total += A[i];
            sum += A[i];
            if (sum < min) {
                min = sum;
                mleft = last;
                mright = i;
            }
            if (sum >= 0) {
                sum = 0;
                last = i+1;
            }
        }
        
        vector<int> ans(2);
        if (mright-mleft+1 != A.size() && total - min > max) {
            ans[0] = mright+1;
            ans[1] = mleft-1;
            if (ans[1] < 0) {
                ans[1] = A.size();
            }
        } else {
            ans[0] = left;
            ans[1] = right;
        }
        return ans;
    }
    
    vector<int> continuousSubarraySumII3(vector<int>& A) {
        vector<int> ans(2);
        if (A.size() == 0) return ans;
        int max = INT_MIN;
        int last = 0;
        int sum = 0;
        vector<int> B(A.size()*2);
        for (int i = 0; i < B.size(); ++i) {
            int index = i;
            if (index >= A.size()) {
                index -= A.size();
            }
            B[i] = A[index];
        }
        for (int i = 0; i < B.size(); ++i) {
            sum += B[i];
            if (sum > max) {
                if (i-last+1 <= A.size()) {
                    max = sum;
                    ans[0] = last;
                    ans[1] = i;
                    if (ans[1] >= A.size()) {
                        ans[1] -= A.size();
                    }
                }
            }
            if (sum <= 0) {
                sum = 0;
                last = i+1;
            }
        }
        return ans;
    } 
    
    vector<int> continuousSubarraySumII2(vector<int>& A) {
        // Write your code here
        vector<int> ans(2);
        if (A.size() == 0) return ans;
        int max = INT_MIN;
        int last = 0;
        int sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            if (sum > max) {
                max = sum;
                ans[0] = last;
                ans[1] = i;
            }
            if (sum <= 0) {
                sum = 0;
                last = i+1;
            }
        }
        if (sum > 0) {
            for (int i = 0; i < last; ++i) {
                sum += A[i];
                if (sum > max) {
                    max = sum;
                    ans[0] = last;
                    ans[1] = i;
                }
                if (sum <= 0) {
                    sum = 0;
                    last = i+1;
                }
            }
        }
        return ans;
    }
};
