/*
题目大意：
给一个1-n的第k个排列。

解题思路：
本来是用下一个排列一个一个的找过去的，竟然超时。
然后就直接用的数学计算的方式计算出来的。

遇到的问题：
一个一个算会超时。
而且，这种算法明显比那样不知道低多少了。
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> buf(n);
        buf[0] = 1;
        for(int i = 1; i < n; ++i){
            buf[i] = buf[i-1]*(i+1);
        }
        string ans;
        k %= buf[n-1];
        if(k == 0){
            for(int i = 1; i <= n; ++i){
                ans.push_back(n-i+1+'0');
            }
            return ans;
        }
        vector<int> nums;
        for(int i = 0; i < n; ++i){
            nums.push_back(i+1);
        }
        for(int i = 0; i < n; ++i){
            if(i == n-1){
                ans.push_back(nums[0]+'0');
                break;
            }
            int x = (k-1)/buf[n-i-2];
            k = (k-1)%buf[n-i-2] + 1;
            ans.push_back(nums[x]+'0');
            nums.erase(nums.begin() + x);
        }
        return ans;
    }
};