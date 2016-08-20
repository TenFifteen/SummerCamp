/*
题目大意：
给定一列房子的钱，两个连着的房子是不可以抢的，问最多可以抢多少钱

解题思路：
动归

遇到的问题：
一次通过

再次阅读：
显然是一个动态规划。
不过之前这种写法，感觉可以把空间压缩掉。
然后还有另一种思路，其实也差不多的：就是a表示当前抢的最后一个是偶数，
b表示当前抢的是奇数。
#define max(a, b) ((a)>(b)?(a):(b))
int rob(int num[], int n) {
    int a = 0;
    int b = 0;

    for (int i=0; i<n; i++)
    {
        if (i%2==0)
        {
            a = max(a+num[i], b);
        }
        else
        {
            b = max(a, b+num[i]);
        }
    }

    return max(a, b);
}
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> rob(nums.size()), norob(nums.size());
        if(nums.size() == 0)return 0;
        rob[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            rob[i] = norob[i-1] + nums[i];
            norob[i] = max(rob[i-1], norob[i-1]);
        }
        return max(rob[nums.size()-1], norob[nums.size()-1]);
    }
};
/*
第二次做：
比较顺利。
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int n = nums.size(), rob = nums[0], norob = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int now = max(rob, norob+nums[i]);
            norob = max(rob, norob);
            rob = now;
        }

        return rob;
    }
};
/*
 * easy
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0, norob = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int new_rob = norob + nums[i];
            norob = max(norob, rob);
            rob = new_rob;
        }
        return max(norob, rob);
    }
};
